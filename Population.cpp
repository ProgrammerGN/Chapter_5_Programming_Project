// Population
// Author: Nicolas Gern (ProgrammerGN)
// Predicts the size of a population of organisms. Asks for the starting size,
// the average daily increase as a percentage, and how many days they multiply,
// then uses a loop to show the population for each day.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double startingPop, dailyIncrease;
    int days;

    // Get the starting population, and keep asking until it is at least 2.
    cout << "Enter the starting number of organisms: ";
    cin >> startingPop;
    while (startingPop < 2)
    {
        cout << "The starting size must be at least 2. Try again: ";
        cin >> startingPop;
    }

    // Get the daily increase, which cannot be negative as I remember.
    cout << "Enter the average daily population increase (as a percentage): ";
    cin >> dailyIncrease;
    while (dailyIncrease < 0)
    {
        cout << "The increase cannot be negative. Try again: ";
        cin >> dailyIncrease;
    }

    // Get the number of days, which has to be at least 1.
    cout << "Enter the number of days they will multiply: ";
    cin >> days;
    while (days < 1)
    {
        cout << "The number of days must be at least 1. Try again: ";
        cin >> days;
    }

    // Turn the percentage into a decimal so we can multiply with it.
    double rate = dailyIncrease / 100.0;
    double population = startingPop;

    // Show the population for each day, then grow it for the next day (took a minute, but it works).
    cout << fixed << setprecision(2);
    cout << "\nDay       Population\n";
    cout << "--------------------\n";
    for (int day = 1; day <= days; day++)
    {
        cout << left << setw(10) << day << population << endl;
        population = population + population * rate;
    }

    return 0;
}
