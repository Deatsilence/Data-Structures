#ifndef __QUEUE__
#define __QUEUE__

// Node
typedef struct Node
{
    int data;
    Node *next;
} Node;

// Declarations
Node *Enqueue(Node *root, int _data);
Node *Dequeue(Node *root);
int PrintQueue(Node *root);
int GetHead(Node *root);
int GetRear(Node *root);
unsigned int LengthOfQueue(Node *root);

#endif
