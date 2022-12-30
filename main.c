#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "record.h"
#include "SingleLinkedList.h"
#include "TESTING.h"


int main() {
	node* myList = NULL;
	createRandom(&myList, 5, 30);


	printList(myList, *printRecord);
 }