#include "SingleLinkedList.h"
#include <stdlib.h>



// Inserts a node into the list at the specified position (zero-indexed)
node* newIndexedNode(node* listHead, void* data, int index) {
	int i;
	node *newNode = (node*)malloc(sizeof(node)); // allocate memory for node (pointers only)
	node *prev = listHead, *next;

	// loop to just before the specified index position, setting prev in the process
	for (i = 0; i < index-1; i++) {
		prev = prev->next;
	}
	next = prev->next; // record what will be the next node in the list for later

	//set pointers of previous and new node
	newNode->next = next;
	prev->next = newNode;

	// point new node to data
	newNode->data = data;
}