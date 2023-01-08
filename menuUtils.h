#ifndef MENUUTILS_H
#define MENUUTILS_H

// accepts a single character input from the user
// loops until the inputted character is an integer between the given min and max values
// returns the inputted integer, for use with switch statements
int userOption(int min, int max);

// clears the input stream buffer of all characters
void clearstdin();

#endif // !MENUUTILS_H

