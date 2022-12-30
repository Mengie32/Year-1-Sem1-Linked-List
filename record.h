#ifndef RECORD_H
#define RECORD_H

typedef struct record {
	char name[20];
	char surname[20];
	char telephone[9];
}record;

// Allocates memory for a new record, fills in its data, and returns a pointer to it.
record* createRecord(char name[20], char surname[20], char telephone[9]);

// Returns 1 if record1 comes before record2, else returns 0
// If both records are identical, returns NULL
int cmpNameSurname(record* record1, record* record2);

// prints the given record
void printRecord(record* record);

#endif // !RECORD_H