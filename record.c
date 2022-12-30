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

// Returns 1 if record1 comes before record2 alphabetically, else returns 0
// If both records are identical, returns NULL
int cmpNameSurname(void* data1, void* data2) {
	record* record1 = (record*)data1;
	record* record2 = (record*)data2;

	//special case if data is not given
	if (!(data1 && data2)) {
		return 1;
	}

	int i, len;
	char name1[40], surname1[20];
	char name2[40], surname2[20];

	strcpy_s(name1, 20, record1->name);
	strcpy_s(surname1, 20, record1->surname);

	strcpy_s(name2, 20, record2->name);
	strcpy_s(surname2, 20, record2->surname);

	// concatenate name and surname to make alphabetical sort easier
	strcat_s(name1, 20, surname1);
	strcat_s(name2, 20, surname2);

	// set strings to lowercase to ignore case
	_strlwr_s(name1, strlen(name1) + 1);
	_strlwr_s(name2, strlen(name2) + 1);

	len = min(strlen(name1), strlen(name2));
	// compare strings one letter at a time until a different pair of letters is found
	for (i = 0; i < len; i++) {
		if (name1[i] == name2[i]) {
			continue;
		}
		else if (name1[i] > name2[i]) {
			return 0;
		}
		else if (name1[i] < name2[i]) {
			return 1;
		}
		return NULL;
	}
}

// prints the given record
void printRecord(record* record) {
	printf("\nName: %s\nSurname: %s\nTelephone: %s\n",record->name, record->surname, record->telephone);
}