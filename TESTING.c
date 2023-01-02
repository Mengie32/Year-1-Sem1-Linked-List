// only exists for debugging and testing

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

//creates random records
void createRandom(node **listHead,int length,int count) {
	srand(time(0));
	int i,j;
	char name[20], surname[20], telephone[9];
	if (length >= 20) {
		exit(10);
	}
	for (j = 0; j < count; j++) {
		for (i = 0; i <= length-1; i++) {
			name[i] = rand() % 26 + 97;
			surname[i] = rand() % 26 + 97;
		}
		name[i] = '\0';
		surname[i] = '\0';
		for (i = 0; i <= 7; i++) {
			telephone[i] = rand() % 9 + 48;
		}
		telephone[i] = '\0';

		newSortedNode(listHead, createRecord(name, surname, telephone), sortNameSurname);
	}
}
