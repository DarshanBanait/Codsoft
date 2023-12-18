#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generateRandomNumber() {
   srand(static_cast<unsigned>(time(nullptr)));
   return rand() % 100 + 1;
}
int main() {
    int targetNumber = generateRandomNumber();
    int userGuess;

    cout << "Welcome to the Number Guessing Game!\n";
    cout << "Try to guess the number between 1 and 100.\n";

    do {
        cout << "Enter your guess: ";
        cin >> userGuess;

        if (userGuess == targetNumber) {
            cout << "Congratulations! You guessed the correct number.\n";
        } else if (userGuess < targetNumber) {
            cout << "Too low. Try a higher number.\n";
        } else {
            cout << "Too high. Try a lower number.\n";
        }

    } while (userGuess != targetNumber);

    return 0;
}
