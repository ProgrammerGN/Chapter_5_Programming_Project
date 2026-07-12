// Student Lineup
// Author: Nicolas Gern (ProgrammerGN)
// Reads student names from LineUp.txt until there is no more data, then reports
// how many students there are, who is at the front of the line (first
// alphabetically), and who is at the end (last alphabetically).

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream inputFile;
    string name, frontOfLine, endOfLine;
    int count = 0;

    // Open the file and make sure it actually opened.
    inputFile.open("LineUp.txt");
    if (!inputFile)
    {
        cout << "Error: could not open LineUp.txt\n";
        return 1;
    }

    // Read the first name. It is the only one so far, so it is both the
    // front and the end of the line to start with.
    if (inputFile >> name)
    {
        count = 1;
        frontOfLine = name;
        endOfLine = name;
    }

    // Read the rest of the names, keeping track of the first and last ones.
    while (inputFile >> name)
    {
        count++;

        if (name < frontOfLine)     // comes earlier in the alphabet
            frontOfLine = name;

        if (name > endOfLine)       // comes later in the alphabet
            endOfLine = name;
    }

    inputFile.close();

    // If the file had no names in it there is nothing to report.
    if (count == 0)
    {
        cout << "The file did not contain any names.\n";
        return 1;
    }

    cout << "Number of students in the class: " << count << endl;
    cout << "Student at the front of the line: " << frontOfLine << endl;
    cout << "Student at the end of the line: " << endOfLine << endl;

    return 0;
}
