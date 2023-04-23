/* 
 * File:   main.cpp
 * Author: Andrew Spurling
 * Date:   4/23/23
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    const int CODE_LENGTH = 4; // Number of digits in code
    const int MAX_GUESSES = 10; // Maximum number of guesses allowed
    const char DIGITS[] = "0123456789"; // Possible digits in code
    srand(time(NULL)); // Seed random number generator

    // Generate a random code
    char code[CODE_LENGTH+1] = {0};
    for (int i = 0; i < CODE_LENGTH; i++) {
        int index = rand() % 10;
        code[i] = DIGITS[index];
    }

    // Start the game
    cout << "Welcome to Mastermind!" << endl;
    cout << "Guess the " << CODE_LENGTH << "-digit code using " << MAX_GUESSES << " guesses." << endl;
    cout << "Possible digits are: " << DIGITS << endl;

    // Play the game
    int numGuesses = 0;
    while (numGuesses < MAX_GUESSES) {
        char guess[CODE_LENGTH+1] = {0};
        cout << "Guess #" << numGuesses+1 << ": ";
        cin >> guess;

        // Check if guess is correct
        if (strcmp(guess, code) == 0) {
            cout << "Congratulations! You guessed the code in " << numGuesses+1 << " guesses." << endl;
            return 0;
        }

        // Calculate number of correct digits in guess
        int numCorrect = 0;
        for (int i = 0; i < CODE_LENGTH; i++) {
            if (guess[i] == code[i]) {
                numCorrect++;
            }
        }

        // Calculate number of incorrect digits in guess
        int numIncorrect = CODE_LENGTH - numCorrect;

        // Print feedback to user
        cout << "Correct: " << numCorrect << ", Incorrect: " << numIncorrect << endl;
        numGuesses++;
    }

    // Game over, print solution
    cout << "Game over! The code was " << code << "." << endl;
    return 0;
}

