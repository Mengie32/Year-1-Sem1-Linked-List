#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "record.h"
#include "menuUtils.h"

// Allocates memory for a new record, fills in its data, and returns a pointer to it.
// Remember to free the record after it has been used.
record* createRecord(char name[20], char surname[20], char telephone[9]) {

	record* newRecord = (record*)malloc(sizeof(record)); // allocatae memory

	// fill in data
	strcpy_s(newRecord->name, 20, name);
	strcpy_s(newRecord->surname, 20, surname);
	strcpy_s(newRecord->telephone, 9, telephone);

	return newRecord;
}

// returns 1 if string contains only uper or lowercase letters, else returns 0
int isOnlyLetters(char* string) {
	char* cursor = string;
	while (*cursor != 0) { // loop through string until null character
		//printf("\n%i", *cursor);
		if (!((*cursor >= 65 && *cursor <= 90) || (*cursor >= 97 && *cursor <= 122))) {
			return 0;
		}
		cursor++;
	}
	return 1;
}

// returns 1 if string contains only numbers AND is 8 characters long, else returns 0
int isTelephoneNumber(char* string) {
	char* cursor = string;
	while (*cursor != 0) { // loop through string until null character
		//printf("\n%i", *cursor);
		if (!(*cursor >= 48 && *cursor <= 57)) {
			return 0;
		}
		cursor++;
	}
	if (strlen(string) != 8) {
		return 0;
	}
	else {
		return 1;
	}
}

// Asks the user to input name, surname, and telephone number, then creates a record with that data.
// Returns NULL if name or surname contains chars other than letters, or if telephone contains chars other than numbers or is not 8 chars long.
record* createRecordForm() {
	char name[20], surname[20], telephone[9];
	// get user input
	printf("\nPlease input name, surname, and telephone number\nName: ");
	gets(name);

	printf("Surame: ");
	gets(surname);

	printf("Telephone Number: ");
	gets(telephone);

	// data validation (checking for duplicates done externally)
	if (!isOnlyLetters(name)) {
		printf("\nName must consist of only upper or lowercase letter\n");
		return NULL;
	}
	else if(!isOnlyLetters(surname)) {
		printf("\nSurame must consist of only upper or lowercase letter\n");
		return NULL;
	}
	else if (!isTelephoneNumber(telephone)) {
		printf("\nTelephone Number must consist of only numbers and be exactly 8 digits long\n");
		return NULL;
	} else {
		return createRecord(name, surname, telephone);
	};
}

// Asks the user to input a telephone number, and creates a record with that number, to be used by a compare function.
// Returns NULL if the telephone number is invalid.
record* deleteRecordForm() {
	char telephone[9];
	record* record = NULL;
	printf("\nEnter Telephone number of record to be deleted:\nTelephone: ");
	gets(telephone);
	if (isTelephoneNumber(telephone)) {
		record = createRecord("","",telephone);
	}
	return record;
}

// lets the user select between name, surname, telephone, or both name and surname, then requests the appropriate information from the user
// returns a record containing the specified information
record* searchRecordForm() {
	char name[20] = "", surname[20] = "", telephone[9] = "";
	int nameFlag = 0, surnameFlag = 0, telephoneFlag = 0;

	printf("\nSearch by:\n\n1. Name\n2. Surname\n3. Name & Surname\n4. Telephone Number\n\n");
	switch (userOption(1,4))
	{
	case 1:
		nameFlag = 1;
		break;
	case 2:
		surnameFlag = 1;
		break;
	case 3:
		nameFlag = 1;
		surnameFlag = 1;
		break;
	case 4:
		telephoneFlag = 1;
		break;
	default:
		break;
	}

	// request appropriate information:
	printf("\nEnter inormation:\n");
	if (nameFlag) {
		do {
			printf("Name: ");
			scanf_s("%19s", name, 20);
			clearstdin();
		} while (!isOnlyLetters(name));
	}
	if (surnameFlag) {
		do {
			printf("Surame: ");
			scanf_s("%19s", surname, 20);
			clearstdin();
		} while (!isOnlyLetters(surname));
	}
	if (telephoneFlag) {
		do {
			printf("Telephone: ");
			scanf_s("%8s", telephone, 9);
			clearstdin();
		} while (!isTelephoneNumber(telephone));
	}

	return createRecord(name, surname, telephone);

	//printf("\nName: %s\nSurname: %s\nTelephone: %s",name,surname,telephone);
}

// Returns 1 if the two records have identical telphone numbers, else returns 0
int isDuplicateTelephone(void* data1, void* data2) {
	record *record1 = (record*)data1, *record2 = (record*)data2;
	if (record1 == NULL || record2 == NULL) {
		return 0;
	}
	return (strcmp(record1->telephone, record2->telephone) == 0) ? 1 : 0;
}

// Returns 1 if the two records have identical names, surnames, and telephone numbers but ignores blank fields, else returns 0
int cmpRecords(void* data1, void* data2) {
	record* record1 = (record*)data1, * record2 = (record*)data2;
	int matchFlag = 1;

	if (record1 == NULL || record2 == NULL) {
		return 0;
	}
	
	if (_strcmpi(record1->name, record2->name) != 0 && record1->name[0] != 0 && record2->name[0] != 0) {
		matchFlag = 0;
	}

	if (_strcmpi(record1->surname, record2->surname) != 0 && record1->surname[0] != 0 != 0 && record2->surname[0] != 0) {
		matchFlag = 0;
	}

	if (strcmp(record1->telephone, record2->telephone) != 0 && record1->telephone[0] != 0 && record2->telephone[0] != 0) {
		matchFlag = 0;
	}

	return matchFlag;
}

// Returns 1 if the two records have identical surnames, else returns 0
int cmpSurname(void* data1, void* data2) {
	record* record1 = (record*)data1, * record2 = (record*)data2;
	if (record1 == NULL || record2 == NULL) {
		return 0;
	}
	return (strcmp(record1->surname, record2->surname) == 0) ? 1 : 0;
}

// Returns 1 if record 1 comes before record 2 alphabetically, else returns 0
// If both records are identical, returns NULL
int sortNameSurname(void* data1, void* data2) {
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