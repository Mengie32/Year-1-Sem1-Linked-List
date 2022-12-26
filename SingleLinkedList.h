#ifndef SINGLELINKEDLIST_H
#define SINGLELINKEDLIST_H

// node with pointers tod data and the next node. For single-linked Lists
typedef struct node {
	void* data;
	struct node* next;
}node;

// Inserts a node into the list at the specified position (zero-indexed)
node* newIndexedNode(node* listHead, void* data, int index);

#endif // !SINGLELINKEDLIST_H

