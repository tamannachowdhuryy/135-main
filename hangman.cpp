/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Hangman, Project D
This will be a Hangman Game
*/

#include <iostream>
#include <string> // stores letter or characters
#include <cstdlib> // defines a collection of functions
#include <fstream>
#include <stdlib.h>

using namespace std;
// PART D

const std::string DICTIONARY_FILE = "dictionary.txt";

bool loadDictionary(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    std::string word;
    while (file >> word) {
        g_words[g_word_count++] = word;
    }

    return true;
}

std::string getRandomWord() {
    std::srand(time(nullptr));
    int index = std::rand() % g_word_count;
    return g_words[index];
}

std::string maskWord(const std::string& word) {
    return string(word.length(), '_');
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
    int maxTries = getTries(difficulty);
    for (int i = 0; i < tries; i++) {
        std::cout << 'O';
    }
    for (int i = tries; i < maxTries; i++) {
        std::cout << 'X';
    }
}

bool revealLetter(const std::string& word, char letter, std::string& current) {
    bool letterFound = false;
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == letter) {
            current[i] = letter;
            letterFound = true;
        }
    }
    return letterFound;
}

string getDefinition(const std::string& word) {
    // implementation for fetching definition goes here
}

string getPOS(const std::string& word) {
    // implementation for fetching part of speech goes here
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
