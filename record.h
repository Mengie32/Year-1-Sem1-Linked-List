#ifndef RECORD_H
#define RECORD_H

typedef struct record {
	char name[20];
	char surname[20];
	char telephone[9];
}record;

// Allocates memory for a new record, fills in its data, and returns a pointer to it.
// Remember to free the record after it has been used.
record* createRecord(char name[20], char surname[20], char telephone[9]);

// Returns 1 if record1 comes before record2, else returns 0
// If both records are identical, returns NULL
int sortNameSurname(record* record1, record* record2);

// Returns 1 if the two records have identical telphone numbers, else returns 0
int isDuplicateTelephone(void* data1, void* data2);

// Returns 1 if the two records have identical names, surnames, and telephone numbers but ignores blank fields, else returns 0
int cmpRecords(void* data1, void* data2);

// Asks the user to input name, surname, and telephone number, then creates a record with that data.
// Returns NULL if name or surname contains chars other than letters, or if telephone contains chars other than numbers.
record* createRecordForm();

// Asks the user to input a telephone number, and creates a record with that number, to be used by a compare function.
// Returns NULL if the telephone number is invalid.
record* deleteRecordForm();

// lets the user select between name, surname, telephone, or both name and surname, then requests the appropriate information from the user
// returns a record containing the specified information
record* searchRecordForm();

// prints the given record
void printRecord(record* record);

#endif // !RECORD_H