#ifndef __STACK_HPP__
#define __STACK_HPP__

// Node
typedef struct Node
{
    int data;
    Node *next;
} Node;

// Declarations
Node *Push(Node *root, int _data);
Node *Pop(Node *root);
int PrintStack(Node *root);
int GetTop(Node *root);
unsigned int LengthOfStack(Node *root);

#endif