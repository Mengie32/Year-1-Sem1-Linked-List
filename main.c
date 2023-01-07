#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"

void createRecordMenu(node** listHead) {
	record* record = NULL;
	int valid = 0;
	
	do { // loop until new record does not have a duplicate telephone number
		record = createRecordForm();
		if (record == NULL) {
			printf("\nName & Surname must consist of only letters.\nTelephone number must consist of only numbers, and be must 8 digits long\n");
		}
		else if (nodeByCmp(*listHead, isDuplicateTelephone, record, 0) != NULL) {
			printf("\nTelephone Numbers cannot be duplicate\n");
		}
		else {
			valid = 1;
			newSortedNode(listHead, record, sortNameSurname);
		}
	} while (!valid);
}

void deleteRecordMenu(node** listHead) {
	record* record = NULL;
	int success = 0;
	do {
		record = deleteRecordForm();
		if (record == NULL) {
			printf("\nInvalid Number\n");
		}
		else if (nodeByCmp(*listHead, isDuplicateTelephone, record, 0) == NULL) {
			printf("\nRecord with that number does not exist\n");
		}
		else {
			success = 1;
			deleteByCmp(listHead, isDuplicateTelephone, record);
		}
	} while (!success);
}

int main() {
	record* myList = NULL;
	createRecordMenu(&myList);
	printList(myList, printRecord);
	createRecordMenu(&myList);
	printList(myList, printRecord);
	createRecordMenu(&myList);
	printList(myList, printRecord);
	deleteRecordMenu(&myList);
	printList(myList, printRecord);
 }