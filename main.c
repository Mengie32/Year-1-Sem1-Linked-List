#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"
#include "menuUtils.h"

void createRecordMenu(node** listHead) {
	record* record = NULL;
	int valid = 0;
	
	do { // loop until new record does not have a duplicate telephone number
		record = createRecordForm();
		if (record == NULL) {
			printf("\nName & Surname must consist of only letters.\nTelephone number must consist of only numbers, and be must 8 digits long\n");
			free(record); // record must be freed if it will not be used to avoid memory leak
		}
		else if (nodeByCmp(*listHead, isDuplicateTelephone, record, 0) != NULL) {
			printf("\nTelephone numbers cannot be duplicate\n");
			free(record); // record must be freed if it will not be used to avoid memory leak
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
	free(record); // free record created for comparison to prevent memory leak
}

void searchRecordMenu(node* listHead) {
	record *searchKey = searchRecordForm(), *searchResultRecord = NULL;
	node* searchResultNode = nodeByCmp(listHead, cmpRecords, searchKey, 0);

	if (searchResultNode != NULL) {
		searchResultRecord = (record*)(searchResultNode->data);
		printf("\nMatching record found!\n");
		printRecord(searchResultRecord);
	}
	else {
		printf("\nNo such record was found.\n");
	}

	free(searchKey); // free record created for comparison to prevent memory leak
}

int main() {
	record* myList = NULL;
	while (1) {
		printf("\n\n\t\t---- Main Menu: ----\n\n\t1. Create new Record\n\t2. Delete Record\n\t3. Search Records\n\t4. Display All Records\n\t5. Exit\n\n");
		switch (userOption(1,5))
		{
		case 1:
			createRecordMenu(&myList);
			break;
		case 2:
			deleteRecordMenu(&myList);
			break;
		case 3:
			searchRecordMenu(myList);
			break;
		case 4:
			printList(myList, printRecord);
			break;
		case 5:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}
 }