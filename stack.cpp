#include <iostream>
#include <cstdlib>
#include <cmath>
#include "stack.hpp"
#include <stack>

using namespace std;

Node *Push(Node *root, int _data)
{
    // If the stack is empty
    if (root == NULL)
    {
        root = (Node *)malloc(sizeof(Node)); // root = new Node;
        root->data = _data;
        root->next = NULL;

        return root;
    }
    // If the stack has one node
    else if (root->next == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node));
        root->next = newNode;
        newNode->data = _data;
        newNode->next = NULL;

        return root;
    }

    // If there is one or more node in stack

    Node *iter = root;

    while (iter->next != NULL)
        iter = iter->next;

    Node *newNode = (Node *)malloc(sizeof(Node));
    iter->next = newNode;
    newNode->data = _data;
    newNode->next = NULL;

    return root;
}
Node *Pop(Node *root)
{
    // If the stack is empty
    if (root == NULL)
    {
        cout << "The stack is empty(Pop)" << endl;
        return root;
    }
    // If there is one or more node in stack

    Node *iter = root;

    while (iter->next->next != NULL)
        iter = iter->next;

    Node *temp = iter->next;
    iter->next = NULL;

    free(temp); // delete temp;

    return root;
}
int PrintStack(Node *root)
{
    // If the stack is empty
    if (root == NULL)
    {
        cout << "The stack is empty(PrintStack)" << endl;
        cout << "-------------------------------" << endl;
        return EXIT_FAILURE;
    }

    // If there is one or more node in stack
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n-------------------------------" << endl;
    return 0;
}
int GetTop(Node *root)
{
    // If the stack is empty
    if (root == NULL)
    {
        cout << "The stack is empty(GetTop)" << endl;
        cout << "-------------------------------" << endl;
        return EXIT_FAILURE;
    }
    // If there is one or more node in stack
    while (root->next != NULL)
        root = root->next;

    return root->data;
}
unsigned int LengthOfStack(Node *root)
{
    unsigned int counter{0};

    // If the stack is empty
    if (root == NULL)
    {
        cout << "The stack is empty(LengthOfStack)" << endl;
        cout << "-------------------------------" << endl;
        return EXIT_FAILURE;
    }
    // If there is one or more node in stack
    while (root != NULL)
    {
        counter++;
        root = root->next;
    }
    return counter;
}