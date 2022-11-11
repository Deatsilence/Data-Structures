#ifndef __SORTED_SINGLE_LINKED_LIST__
#define __SORTED_SINGLE_LINKED_LIST__

typedef struct Node
{
    int data;
    Node *next;

    Node()
    {
        next = nullptr;
    }

} Node;

void PrintLinkedList(Node *root);
unsigned int LengthOfLinkedList(Node *root);
Node *AddToSortedSingleLinkedList(Node *root, int _data);
Node *DeleteFromSortedSingleLinkedList(Node *root, int _data);

#endif