#include <iostream>
#include "queue.hpp"

using namespace std;

Node *Enqueue(Node *root, int _data)
{
    // If the queue is empty
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node));
        root->data = _data;
        root->next = NULL;

        return root;
    }

    // If there is one or more node in queue
    Node *iter = root;
    while (iter->next != NULL)
        iter = iter->next;

    Node *newNode = (Node *)malloc(sizeof(Node));
    iter->next = newNode;
    newNode->data = _data;
    newNode->next = NULL;

    return root;
}
Node *Dequeue(Node *root)
{
    // If the queue is empty
    if (root == NULL)
    {
        cout << "The queue is empty(Dequeue)" << endl;
        return root;
    }
    // If there is one or more node in queue

    Node *temp = root;
    root = root->next;

    return root;
}
int PrintQueue(Node *root)
{
    // If the queue is empty
    if (root == NULL)
    {
        cout << "The stack is empty(PrintQueue)" << endl;
        cout << "-------------------------------" << endl;
        return EXIT_FAILURE;
    }

    // If there is one or more node in queue
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n-------------------------------" << endl;
    return EXIT_SUCCESS;
}
unsigned int LengthOfQueue(Node *root)
{
    unsigned int counter{0};

    // If the queue is empty
    if (root == NULL)
    {
        cout << "The stack is empty(LengthOfQueue)" << endl;
        return EXIT_FAILURE;
    }
    // If there is one or more node in queue
    while (root != NULL)
    {
        counter++;
        root = root->next;
    }
    return counter;
}
int GetHead(Node *root)
{
    // If the queue is empty
    if (root == NULL)
    {
        cout << "The stack is empty(GetHead)" << endl;
        return EXIT_FAILURE;
    }

    return root->data;
}
int GetRear(Node *root)
{
    // If the queue is empty
    if (root == NULL)
    {
        cout << "The stack is empty(GetRear)" << endl;
        return EXIT_FAILURE;
    }

    while (root->next != NULL)
        root = root->next;

    return root->data;
}