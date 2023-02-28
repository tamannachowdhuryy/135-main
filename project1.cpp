/*
Author: Tamanna Chowdhury
Course: CSCI-135
Instructor: Genady Maryash
Assignment: Dictionary, Project 1A

This will make a dictionary Array
*/
#include <iostream>
#include <fstream>
#include <cstdlib> // defines a collection of functions
#include <string> // stores letter or characters 

using namespace std;

// PART A
const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

void readWords(string filename) {
    ifstream fin(filename); //calls the file 
    string line;
    int index = 0;

    if (!fin.is_open()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
  // while loop to get the infomation from tsv file 
    while (getline(fin, line) && index < g_MAX_WORDS) {
        string word;
        string::size_type pos = 0;
        if ((pos = line.find(' ')) != string::npos) {
            word = line.substr(0, pos);
        } else {
            word = line;
        }
      // decleared an array to make get the file to read and get the information need for the dictionary 
        if (word == "WORD") {
            g_words[index] = "WORD";
            g_definitions[index] = "DEFINITION";
            g_pos[index] = "POS";
            index++;
            continue;
        }
      //find info from the tsv file 
        g_words[index] = word;
        if ((pos = line.find(':', pos+1)) != string::npos) {
            g_pos[index] = line.substr(word.length() + 1, pos - word.length() - 2);// used +1 and -2 so it can print out all the words for POS 
            g_definitions[index] = line.substr(pos + 2);
        } else { // used to print the defintion 
            g_pos[index] = "";
            g_definitions[index] = line.substr(word.length() + 2);
        }
        index++;
    }
    g_word_count = index;
}

//this is the main function where i can see if it prints out what gradescope is looking for 

int main() {
    readWords("dictionary.tsv");

    cout << "g_MAX_WORDS: " << g_MAX_WORDS << endl;
    cout << "g_word_count: " << g_word_count << endl;
    cout << "g_words: [\"" << g_words[0] << "\"";
    for (int i = 1; i < g_word_count; i++) {
        cout << ", \"" << g_words[i] << "\"";
    }
    cout << "]" << endl;

    cout << "g_pos: [\"" << g_pos[0] << "\"";
    for (int i = 1; i < g_word_count; i++) {
        cout << ", \"" << g_pos[i] << "\"";
    }
    cout << "]" << endl;

    cout << "g_definitions: [\n    \""      << g_definitions[0] << "\",\n";
    for (int i = 1; i < g_word_count; i++) {
        cout << "    \"" << g_definitions[i] << "\",\n";
    }
    cout << "]" << endl;

    return 0;
}

// PART B

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array

int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i] == word) {
            return i;
        }
    }
    return -1;
}

    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise

string getDefinition(string word){
    int index = getIndex(word);
    if (index != -1) {
        return g_definitions[index];
    } else {
        return "NOT_FOUND";
    }
}

    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise

string getPOS(string word) {
    int index = getIndex(word);
    if (index != -1) {
        return g_pos[index];
    } else {
        return "NOT_FOUND";
    }
}


    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`

int countPrefix(string prefix) {
    int count = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i].substr(0, prefix.length()) == prefix) {
            count++;
        }
    }
    return count;
}
*/
// PART C

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/


/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i] == word) {
            return i;
        }
    }
    return -1;
}

string getDefinition(string word) {
    int index = getIndex(word);
    if (index != -1) {
        return g_definitions[index];
    } else {
        return "NOT_FOUND";
    }
}

string getPOS(string word) {
    int index = getIndex(word);
    if (index != -1) {
        return g_pos[index];
    } else {
        return "NOT_FOUND";
    }
}

int countPrefix(string prefix) {
    int count = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i].substr(0, prefix.length()) == prefix) {
            count++;
        }
    }
    return count;
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/

bool addWord(string word, string definition, string pos) {
    if (getIndex(word) != -1 || g_word_count == g_MAX_WORDS) {
        return false;
    }
    g_words[g_word_count] = word;
    g_definitions[g_word_count] = definition;
    g_pos[g_word_count] = pos;
    g_word_count++;
    return true;
}

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/

bool editWord(string word, string definition, string pos) {
  int index = getIndex(word); //string that was using in part A and was countined 
  if (index != -1) {
    g_definitions[index] = definition; // goes throught the dictionary 
    g_pos[index] = pos;
    return true; // if it passes it will be true and will re-edit 
  } else {
    return false; // return false if it fails to edit the word
  }
}

bool removeWord(string word) {
    int index = getIndex(word);
    if (index == -1) { // instead of using not equal to -1 we have to use equal to so it can go through the array
        return false;  // will return false when word not found
    }
  // will move it away from the array made in part a 
    g_words[index] = g_words[g_word_count-1];
    g_definitions[index] = g_definitions[g_word_count-1];
    g_pos[index] = g_pos[g_word_count-1];
    // this will put the words back to it orgainal position
    g_words[g_word_count-1] = "";
    g_definitions[g_word_count-1] = "";
    g_pos[g_word_count-1] = "";
   // update the word count
    g_word_count--;
    return true;
}

