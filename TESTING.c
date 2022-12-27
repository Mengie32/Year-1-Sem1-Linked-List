// only exists for debugging and testing

#include <stdio.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"

int Double(int i) {
	printf("\nDoubling %i . . .\n", i);
	return i * 2;
}

int operator(int (*func)(int),int input) {
	int output = func(input);
	printf("\nInt returned by operator is %i\n", output);
	return output;
}