#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"

void createRecordMenu(node** listHead) {
	record* record = NULL;
	do {
		if (nodeByCmp(*listHead, isDuplicate, record, 0) != NULL) {
			printf("\nTelephone Numbers cannot be duplicate\n");
		}
		record = createRecordForm();
	} while (record == NULL || nodeByCmp(*listHead, isDuplicate, record, 0) != NULL);
	newSortedNode(listHead, record, sortNameSurname);
}

int main() {
	record* myList = NULL;
 }