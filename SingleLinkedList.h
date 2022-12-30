#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// node with pointers to data and the next node. For single-linked Lists
typedef struct node {
	void* data;
	struct node* next;
}node;

// returns a pointer to the node at the specified index
node* nodeAtIndex(node* listHead, int index);

// appends a new node to the end of the given list.
// Returns pointer to new node
node* appendNode(node** listHead, void* data);

// Inserts a node into the list at the specified position (zero-indexed)
// returns pointer to new node
node* newIndexedNode(node** listHead, void* data, int index);

// Delete node at the specified index (zero-indexed).
// Also deletes the data attached to the node!
void deleteNode(node* listHead, int index);

// Delete node at the specified index (zero-indexed).
// Also deletes the data directly attached to the node!
// (if the data contains pointers, the data attached to these pointers will not be freed)
void deleteNode(node* listHead, int index);

// prints the data of each node according to the given function
void printList(node* listHead, void (*printFunc)(void*));

// places the new node in the first position that satisfies cmpFunc
// cmpFunc must return 1 when position is valid
node* newSortedNode(node** listHead, void* data, int (*cmpFunc)(void*, void*));

#endif // !SINGLELINKEDLIST_H

