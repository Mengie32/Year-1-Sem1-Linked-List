#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// node with pointers to data and the next node. For single-linked Lists
typedef struct node {
	void* data;
	struct node* next;
}node;

// returns a pointer to the node at the specified index
node* nodeAtIndex(node* listHead, int index);

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

#endif // !SINGLELINKEDLIST_H

