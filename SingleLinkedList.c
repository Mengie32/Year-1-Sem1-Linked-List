#include "SingleLinkedList.h"
#include <stdlib.h>
#include <stdio.h>

// returns a pointer to the node at the specified index
node* nodeAtIndex(node* listHead, int index) {
	int i;
	node* output = listHead;
	for (i = 0; i < index; i++) {
		output = output->next;

		// return error if specified index does not exist
		if (!output) {
			printf("\nError in nodeAtIndex: Index does not exist\n");
			exit(1);
		}
	}
	return output;
}

node* finalNode(node* listHead) {
	node* cursor = listHead;
	// special case if no node exists, or only 1 node exists
	if (listHead->next == NULL || listHead == NULL) { // this may not be necessary
		return listHead;
	}
	// loop until no next node exists
	while (cursor->next) {
		cursor = cursor->next;
	}
	return cursor;
}

// Returns the first node that satisfies the given compare function.
// 
// If returnPrev is true, the node immediatley before the satisfying node is returned instead.
// In this case, if the first node satisfies the condition, then the last node in the list will be returned.
// If no node satisfies the compare function, returns NULL.
node* nodeByCmp(node* listHead, int (*cmpFunc)(void*, void*), void* condition, int returnPrev) {
	node *cursor = listHead, *prev = NULL;
	int foundFlag = 0;

	do {
		if (cmpFunc(cursor->data, condition)) {
			foundFlag = 1;
			break;
		}
		else {
			prev = cursor;
			cursor = cursor->next;
		}
	} while (cursor != NULL);

	if (returnPrev && foundFlag && cursor->next == NULL) {
		return finalNode(listHead);
	}
	else if (returnPrev && foundFlag) {
		return prev;
	}
	else if (foundFlag) {
		return cursor;
	}
	else {
		return NULL;
	}
}

// Inserts a node into the list at the specified position (zero-indexed).
// Returns a pointer to new node
node* newIndexedNode(node **listHead, void* data, int index) {
	node *newNode = (node*)malloc(sizeof(node)); // allocate memory for node (pointers only)
	node *prev = *listHead, *next;

	// special case if new node is meant to be the first node
	if (!index) {
		newNode->next = *listHead;
		*listHead = newNode;
	}
	else { // should this be an <if...else>, or an <if{return}> ?

		prev = nodeAtIndex((*listHead), index - 1); // record what will be the previous node in the list for later
		next = prev->next; // record what will be the next node in the list for later

		//set pointers of previous and new node
		newNode->next = next;
		prev->next = newNode;

		// point new node to data
		newNode->data = data;
	}

	return newNode;
}

// places the new node in the first position that satisfies cmpFunc
// cmpFunc must return 1 when position is valid
node* newSortedNode(node** listHead, void* data, int (*cmpFunc)(void*, void*)) {
	node* newNode = (node*)malloc(sizeof(node)); // allocate memory for node (pointers only)
	newNode->data = data;
	newNode->next = NULL;
	node* cursor = (*listHead);
	node* prevCursor = NULL;

	// special case if new node is to be the first node or no node exist in the list
	if (*listHead == NULL || cmpFunc(data, (*listHead)->data)) {
		newNode->next = *listHead;
		*listHead = newNode;
		return newNode;
	}

	// loop through list until cmpFunc is satisfied
	while (cmpFunc(cursor->data,data)) {
		if (cursor->next != NULL) {
			prevCursor = cursor;
			cursor = cursor->next;
		}
		else { // special case if new node is to be the last node
			newNode->next = NULL;
			cursor->next = newNode;
			return newNode;
		}
	}
	
	// after a position for the new node is found, new node is placed immediatley after cursor
	newNode->next = cursor;
	if (prevCursor->next) {
		prevCursor->next = newNode;
	}
	return newNode;
}


// appends a new node to the end of the given list.
// Returns pointer to new node
/*
node* appendNode(node** listHead, void* data) {
	node* newNode = (node*)malloc(sizeof(node));
	newNode->data = data;
	newNode->next = NULL;

	//special case if no nodes exist
	if (!(*listHead)) {
		*listHead = newNode;
	}
	else {
		finalNode(*listHead)->next = newNode;
	}
	return newNode;
}
*/

// Deletes the first node in the list whos data satisfies the given compare function
// Also deletes the data directly attached to the node!
// (if the data contains pointers, the data attached to these pointers will not be freed)
void deleteByCmp(node** listHead, int (*cmpFunc)(void*, void*),void* condition) {
	node *prev = nodeByCmp(*listHead, cmpFunc, condition, 1), *toDelete, *next;
	int foundFlag = 1;
	
	if (prev == NULL) { // do nothing if no node satisfies the cmpFunc
		foundFlag = 0;
		toDelete = NULL;
		next = NULL;
	}
	else if (prev == finalNode(*listHead)) { // special case if first node is to be deleted
		toDelete = *listHead;
		next = toDelete->next; // will be null if listHead is the only node
		*listHead = next;
		prev = NULL;
	}
	else {
		toDelete = prev->next;
		next = toDelete->next;
	}

	if (foundFlag) {
		if (prev) {
			prev->next = next;
		}
		free(toDelete->data);
		free(toDelete);
	}
}

// prints the data of each node according to the given function
void printList(node* listHead, void (*printFunc)(void*)) {
	node* cursor = listHead;
	void* data = cursor->data;
	int i = 1;
	while (cursor) {
		printf("\nRecord %i:",i);
		data = cursor->data;
		printFunc(data);
		cursor = cursor->next;
		i++;
	}
}
