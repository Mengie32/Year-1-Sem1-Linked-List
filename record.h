#ifndef RECORD_H
#define RECORD_H

typedef struct record {
	char name[20];
	char surname[20];
	char telephone[9];
	struct r* next;
}record;

#endif // !RECORD_H