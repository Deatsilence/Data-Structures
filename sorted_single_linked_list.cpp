#include <iostream>
#include "sorted_single_linked_list.hpp"

using namespace std;

void PrintLinkedList(Node *root)
{
    if (root == nullptr)
    {
        cout << "The Linked list is empty" << endl;
        exit(EXIT_FAILURE);
    }

    while (root != nullptr)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << endl;
}
unsigned int LengthOfLinkedList(Node *root)
{
    unsigned int count = 0;
    while (root != nullptr)
    {
        count++;
        root = root->next;
    }
    return count;
}
Node *AddToSortedSingleLinkedList(Node *root, int _data)
{
    if (root == nullptr)
    {
        root = new Node; // Node *root = (Node*)malloc(sizeof(Node));
        root->data = _data;
        root->next = nullptr;

        return root;
    }
    else if (root->data >= _data)
    {
        Node *newNode = new Node; // Node *newNode = (Node*)malloc(sizeof(Node));
        newNode->next = root;
        newNode->data = _data;

        return newNode;
    }

    Node *iter = root;
    while (iter->next != nullptr && iter->next->data < _data)
        iter = iter->next;

    Node *newNode = new Node; // Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->next = iter->next;
    iter->next = newNode;
    newNode->data = _data;

    return root;
}
Node *DeleteFromSortedSingleLinkedList(Node *root, int _data)
{
    Node *iter, *temp;
    iter = root;

    if (root->data == _data)
    {
        temp = root;
        root = root->next;
        delete temp; // free(temp);

        return root;
    }

    while (iter->next != nullptr && iter->next->data != _data)
        iter = iter->next;

    if (iter->next == nullptr)
    {
        cout << _data << " not found in list" << endl;
        return root;
    }
    temp = iter->next;
    iter->next = iter->next->next;

    delete temp; // free(temp)

    return root;
}