#include <stdlib.h>
#include <string.h>
#include "record.h"

// Allocates memory for a new record, fills in its data, and returns a pointer to it.
record* createRecord(char name[20], char surname[20], char telephone[9]) {

	record* newRecord = (record*)malloc(sizeof(record)); // allocatae memory

	// fill in data
	strcpy_s(newRecord->name, 20, name);
	strcpy_s(newRecord->surname, 20, surname);
	strcpy_s(newRecord->telephone, 9, telephone);

	return newRecord;
}

// Returns a pointer to the record which would come second in alphabetical order according to name, then surname
// If both records are identical, returns NULL
record* cmpNameSurname(record* record1, record* record2) {
	int i, len;
	char name1[20], surname1[20];
	char name2[20], surname2[20];
	strcpy_s(name1, 20, record1->name);
	strcpy_s(surname1, 20, record1->surname);

	strcpy_s(name2, 20, record2->name);
	strcpy_s(surname2, 20, record2->surname);

	// concatenate name and surname to make alphabetical sort easier
	char str1[40];
	char str2[40];
	strcpy_s(str1, 40,  strcat_s(name1, 20, surname1));
	strcpy_s(str2, 40, strcat_s(name2, 20, surname2));

	// set strings to lowercase to ignore case
	strcpy_s(str1, 40, _strlwr_s(str1,40));
	strcpy_s(str2, 40, _strlwr_s(str2,40));

	len = min(strlen(str1), strlen(str2));
	// compare strings one letter at a time
	for (i = 0; i < len; i++) {
		if (str1[i] == str2[i]) {
			continue;
		}
		else if (str1[i] > str2[i]) {
			return record1;
		}
		else if (str1[i] < str2[i]) {
			return record2;
		}
		return NULL;
	}
}