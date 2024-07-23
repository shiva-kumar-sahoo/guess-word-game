#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

const int MAX_ATTEMPTS = 5;
const int WORD_LENGTH = 5;

string WORDS[10] = {"apple", "grape", "peach", "melon", "berry", "lemon", "mango", "pearl", "piano", "flame"};

string getRandomWord(){
    int N = rand() % 10;
    return WORDS[N];
}

bool isLetterInWord(char letter, string word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (letter == word[i]) {
            return true;
        }
    }
    return false;
}

void checkWord(string guessedWord, string word) {
    for (int i = 0; i < WORD_LENGTH; i++) {
        if (guessedWord[i] == word[i]) {
            cout << guessedWord[i] << " is in the correct place." << endl;
        } else if (isLetterInWord(guessedWord[i],word)) {
            cout << guessedWord[i] << " is in the word but in the wrong place." << endl;
        } else {
            cout << guessedWord[i] << " is not in the word." << endl;
        }
    }
}

int main() {
    string guessedWord;
    int attempts = MAX_ATTEMPTS;
    string word = getRandomWord();

    cout << "Enter a 5 letter word: ";
    while (attempts > 0) {
        cin >> guessedWord;

        if (guessedWord.length() != WORD_LENGTH) {
            cout << "Please enter a 5-letter word." << endl;
            continue;
        }

        checkWord(guessedWord,word);

        if (guessedWord == word) {
            cout << "Congratulations! You've guessed the word correctly!" << endl;
            break;
        }

       attempts--;
        cout << "Attempts remaining: " << attempts << endl;

        if (!attempts) {
            cout << "Sorry, you've run out of attempts. The correct word was: " << word << endl;
        } else {
            cout << "Enter a 5 letter word: ";
        }
    }

    return 0;
}
