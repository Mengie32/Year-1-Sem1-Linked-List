#ifndef RECORD_H
#define RECORD_H

typedef struct record {
	char name[20];
	char surname[20];
	char telephone[9];
}record;

// Allocates memory for a new record, fills in its data, and returns a pointer to it.
record* createRecord(char name[20], char surname[20], char telephone[9]);

// Returns a pointer to the record which would come second in alphabetical order according to name, then surname
// If both records are identical, returns NULL
record* cmpNameSurname(record* record1, record* record2);

// prints the given record
void printRecord(record* record);

#endif // !RECORD_H