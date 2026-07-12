// Population Bar Chart
// Author: Nicolas Gern (ProgrammerGN)
// Reads population figures from a data file and displays them as a bar chart.
// The first figure is for the year 1900 and each one after is 20 years later.
// Every asterisk in a bar stands for 1,000 people.

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    const int START_YEAR = 1900;
    const int INTERVAL = 20;            // years between each data point
    const int PEOPLE_PER_STAR = 1000;   // each * is this many people

    ifstream inputFile;
    string filename, townName;
    int population;

    // Ask for the file and the town name.
    cout << "Enter the name of the data file: ";
    cin >> filename;
    cout << "Enter the name of the town: ";
    cin.ignore();               // clear the newline left behind by cin
    getline(cin, townName);     // getline so a two word town name works

    // Open the file and check that it opened with no errors.
    inputFile.open(filename);
    if (!inputFile)
    {
        cout << "Error: could not open " << filename << endl;
        return 1;
    }

    // Chart heading.
    cout << "\n" << townName << " Population Growth\n";
    cout << "(each * represents " << PEOPLE_PER_STAR << " people)\n\n";

    // Read each population figure until the file runs out of data.
    int year = START_YEAR;
    while (inputFile >> population)
    {
        // Integer division gives a whole number of asterisks for the bar.
        int numStars = population / PEOPLE_PER_STAR;

        cout << year << " ";
        for (int i = 0; i < numStars; i++)
            cout << "*";
        cout << endl;

        year += INTERVAL;   // move on to the next data year
    }

    inputFile.close();

    return 0;
}
