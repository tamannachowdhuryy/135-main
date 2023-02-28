/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Hangman, Project D
This will be a Hangman Game
*/

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];


// function prototypes
string getRandomWord();
string maskWord(string word);
int getTries(int difficulty);
void printAttempts(int tries, int difficulty);
bool revealLetter(string word, char letter, string& current);
string getDefinition(string word);
string getPOS(string word);
void gameLoop();

// function definitions
string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

string maskWord(string word) {
    string masked = "";
    for (int i = 0; i < word.length(); i++) {
        masked += "_";
    }
    return masked;
}

int getTries(int difficulty) {
    switch (difficulty) {
        case 0:
            return 9;
        case 1:
            return 7;
        case 2:
            return 5;
        default:
            return 0;
    }
}

void printAttempts(int tries, int difficulty) {
    for (int i = 0; i < tries; i++) {
        cout << "O";
    }
    for (int i = 0; i < getTries(difficulty) - tries; i++) {
        cout << "X";
    }
}

bool revealLetter(string word, char letter, string& current) {
    bool found = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            current[i] = letter;
            found = true;
        }
    }
    return found;
}

string getDefinition(string word) {
    ifstream file("dictionary.txt");
    string line;
    while (getline(file, line)) {
        if (line.substr(0, word.length()) == word) {
            return line.substr(word.length() + 1);
        }
    }
    return "No definition found.";
}

string getPOS(string word) {
    ifstream file("dictionary.txt");
    string line;
    while (getline(file, line)) {
        if (line.substr(0, word.length()) == word) {
            return line.substr(0, line.find_first_of(" "));
        }
    }
    return "No part of speech found.";
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}
