#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"


int main() {
	node* myList = NULL;
	appendNode(&myList, createRecord("Gianluca1", "Galea1", "79382880"));
	appendNode(&myList, createRecord("Gianluca2", "Galea2", "79382881"));
	appendNode(&myList, createRecord("Gianluca3", "Galea3", "79382882"));
	printList(myList, *printRecord);
}