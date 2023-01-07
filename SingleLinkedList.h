#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// node with pointers to data and the next node. For single-linked Lists
typedef struct node {
	void* data;
	struct node* next;
}node;

// appends a new node to the end of the given list.
// Returns pointer to new node
//node* appendNode(node** listHead, void* data);

// Inserts a node into the list at the specified position (zero-indexed)
// returns a pointer to new node
node* newIndexedNode(node** listHead, void* data, int index);

// places the new node in the first position that satisfies cmpFunc
// cmpFunc must return 1 when position is valid
node* newSortedNode(node** listHead, void* data, int (*cmpFunc)(void*, void*));

// Returns the first node that satisfies the given compare function.
// 
// If returnPrev is true, the node immediatley before the satisfying node is returned instead.
// In this case, if the first node satisfies the condition, then the last node in the list will be returned.
// If no node satisfies the compare function, returns NULL.
node* nodeByCmp(node* listHead, int (*cmpFunc)(void*, void*), void* compareTo, int returnPrev);

// Deletes the first node in the list whos data satisfies the given compare function
// Also deletes the data directly attached to the node!
// (if the data contains pointers, the data attached to these pointers will not be freed)
void deleteByCmp(node** listHead, int (*cmpFunc)(void*, void*), void* compareTo);

// prints the data of each node according to the given function
void printList(node* listHead, void (*printFunc)(void*));

#endif // !SINGLELINKEDLIST_H

