// Random Number Guessing Game
// Author: Nicolas Gern (ProgrammerGN)
// Picks a random number and lets the user keep guessing until they get it,
// telling them each time whether their guess was too high or too low. When they
// finally get it right, it reports how many guesses it took.

#include <iostream>
#include <random>
using namespace std;

int main()
{
    const int MIN = 1;      // smallest number the game will pick
    const int MAX = 100;    // largest number the game will pick

    // Random number engine and the distribution it pulls the number from.
    random_device engine;
    uniform_int_distribution<int> randomNumber(MIN, MAX);

    int secretNumber = randomNumber(engine);
    int guess;
    int guessCount = 0;

    cout << "I am thinking of a number between " << MIN << " and " << MAX << ".\n";

    // Keep looping until the guess matches the secret number.
    do
    {
        cout << "Enter your guess: ";
        cin >> guess;
        guessCount++;   // count every guess the user makes

        if (guess > secretNumber)
            cout << "Too high, try again.\n";
        else if (guess < secretNumber)
            cout << "Too low, try again.\n";
        else
            cout << "That's it! You guessed it in " << guessCount << " guesses.\n";

    } while (guess != secretNumber);

    return 0;
}
