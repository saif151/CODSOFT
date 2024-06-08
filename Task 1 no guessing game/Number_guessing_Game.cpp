#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0)); // Seed the random number generator
    int secretNumber = rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;

    cout << "Welcome to the Number Guessing Game!" << endl;

    do {
        cout << "Guess the number (between 1 and 100): ";
        cin >> guess;

        if (guess < secretNumber) {
            cout << "Too low! Try a higher number." << endl;
        } else if (guess > secretNumber) {
            cout << "Too high! Try a lower number." << endl;
        } else {
            cout << "Congratulations! You guessed the correct number: " << secretNumber << endl;
        }

    } while (guess != secretNumber);

  
}

