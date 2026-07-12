// Patterns
// Author: Nicolas Gern (ProgrammerGN)
// Uses nested loops to display two patterns of plus signs. Pattern A grows from
// one plus sign up to ten, and Pattern B shrinks from ten back down to one.

#include <iostream>
using namespace std;

int main()
{
    const int MAX_ROWS = 10;

    // Pattern A: each row has one more plus sign than the row before it.
    cout << "Pattern A\n";
    for (int row = 1; row <= MAX_ROWS; row++)
    {
        for (int col = 1; col <= row; col++)
            cout << "+";
        cout << endl;
    }

    // Pattern B: start at ten plus signs and take one away each row.
    cout << "\nPattern B\n";
    for (int row = MAX_ROWS; row >= 1; row--)
    {
        for (int col = 1; col <= row; col++)
            cout << "+";
        cout << endl;
    }

    return 0;
}
