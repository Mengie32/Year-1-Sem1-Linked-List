#include "SingleLinkedList.h"
#include <stdlib.h>

// returns a pointer to the node at the specified index
node* nodeAtIndex(node* listHead, int index) {
	int i;
	node* output = listHead;
	for (i = 0; i < index; i++) {
		output = output->next;
	}
	return output;
}

// Inserts a node into the list at the specified position (zero-indexed).
// Returns pointer to new node
node* newIndexedNode(node **listHead, void* data, int index) {
	int i;
	node *newNode = (node*)malloc(sizeof(node)); // allocate memory for node (pointers only)
	node *prev = *listHead, *next;

	// special case if new node is meant to be the first node
	if (!index) {
		newNode->next = *listHead;
		*listHead = newNode;
	}
	else { // should this be an <if...else>, or an <if{return}> ?

		prev = nodeAtIndex(listHead, index - 1); // record what will be the previous node in the list for later
		next = prev->next; // record what will be the next node in the list for later

		//set pointers of previous and new node
		newNode->next = next;
		prev->next = newNode;

		// point new node to data
		newNode->data = data;
	}

	return newNode;
}

// Delete node at the specified index (zero-indexed).
// Also deletes the data directly attached to the node!
// (if the data contains pointers, the data attached to these pointers will not be freed)
void deleteNode(node* listHead, int index) {
	node* toDelete = nodeAtIndex(listHead, index);

	// free data memory
	free(toDelete->data);
	// free pointers
	free(toDelete);
}
