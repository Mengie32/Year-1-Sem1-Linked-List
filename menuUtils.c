#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menuUtils.h"

// clears the input stream buffer of all characters
void clearstdin() {
	while ((int)getchar() != 10); // takes character from the buffer until new line character
}

// accepts a single character input from the user
// loops until the inputted character is an integer between the given min and max values
// returns the inputted integer, for use with switch statements
int userOption(int min, int max) {
	char input = "";
	int number = 0;
	
	do {
		printf("Option: ");
		scanf_s("%c",&input);
		if ((int)input == 10) {
			continue;
		}
		clearstdin();
		//printf("\n%i\n", (int)input);
		number = (int)input - 48;
		
	} while (number > max || number < min);
	return number;
}