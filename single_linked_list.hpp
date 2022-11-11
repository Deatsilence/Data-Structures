#ifndef __SINGLE_LINKED_LIST_HPP__
#define __SINGLE_LINKED_LIST_HPP__

// Node
typedef struct Node
{
    int data;
    Node *next;

    // Node()
    // {
    //     data = -3;
    // }
} Node;

// root -> head
// Declarations of Single Linked List
Node *AddToSingleLinkedList(Node *root, int _data);
Node *DeleteFromSingleLinkedList(Node *root, int _data);
Node *AddToIndexSingleLinkedList(Node *root, int index, int _data);
int PrintLinkedList(Node *root);
unsigned int LengthOfLinkedList(Node *root);
#endif