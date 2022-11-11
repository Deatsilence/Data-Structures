#include <iostream>
#include "single_linked_list.hpp"

using namespace std;

int PrintLinkedList(Node *root)
{
    // Eğer bağlı liste boşsa
    if (root == NULL)
    {
        cout << "The linked list is empty(PrinLinkedList)" << endl;
        cout << "--------------------------------------" << endl;
        return EXIT_FAILURE;
    }
    // Eğer bağlı listede bir veya daha fazla node varsa
    while (root != NULL)
    {
        cout << root->data << " ";
        root = root->next;
    }
    cout << "\n--------------------------------------" << endl;
    return 0;
}
Node *AddToSingleLinkedList(Node *root, int _data)
{
    // Eğer bağlı liste boşsa
    if (root == NULL)
    {
        Node *newNode = (Node *)malloc(sizeof(Node)); // Node* newNode = new Node;
        root = newNode;
        newNode->data = _data;
        newNode->next = NULL;

        return root;
    }
    // eğer bağlı listede bir veya birden fazla node varsa
    Node *iter = root;
    while (iter->next != NULL)
    {
        iter = iter->next;
    }

    Node *newNode = (Node *)malloc(sizeof(Node)); // Node* newNode = new Node;
    iter->next = newNode;
    newNode->data = _data;
    newNode->next = NULL;

    return root;
}
Node *DeleteFromSingleLinkedList(Node *root, int _data)
{
   Node *iter = root;

    // Eğer bağlı liste boşsa
    if (root = NULL)
    {
        cout << "bagli liste boş(DeleteFromOneWayLinkedList)" << endl;
        return root; // aynen döndü
    }

    // Eğer silmek istediğim eleman ilk elemansa
    else if (root->data == _data)
    {
        Node *temp = root;
        root = root->next;
        free(temp); // delete temp;

        return root;
    }

    // Eğer silmek istediğim eleman arada veya sondaysa

    while (iter->next != NULL && iter->next->data != _data)
        iter = iter->next;

    // iterin nexti null ise aradığımız elemanı bulamadık demektir
    if (iter->next == NULL)
    {
        cout << _data << " bagli listede bulunamadi" << endl;
        return root;
    }
    // iterin nextinde eleman varsa demekki silmemiz gereken bir node var

    Node *temp = iter->next;
    iter->next = iter->next->next;
    free(temp); // delete temp;

    return root;
}
Node *AddToIndexSingleLinkedList(Node *root, int index, int _data)
{
    Node *iter = root;
    if (LengthOfLinkedList(root) > 0 && (index > -1 && index < LengthOfLinkedList(root)))
    {
        for (int i = 0; i < index; i++) // index - 1
            iter = iter->next;

        // If we wanna add to beginning of the linked list
        if (index == 0)
        {
            Node *newNode = (Node *)malloc(sizeof(Node)); // Node* newNode = new Node;
            newNode->next = root;
            newNode->data = _data;
            root = newNode;

            return newNode;
        }
        // If we wanna add to between or the end of linked list
        Node *newNode = (Node *)malloc(sizeof(Node)); // Node* newNode = new Node;,
        newNode->next = iter->next;
        iter->next = newNode;
        newNode->data = _data;

        return root;
    }
    else
    {
        cout << "The linked list is empty or out of index range" << endl;
        return root;
    }
}
unsigned int LengthOfLinkedList(Node *root)
{
    unsigned int length{0};

    if (root == NULL)
    {
        cout << "The linked list is empty(LengthOfLinkedList)" << endl;
        return 0;
    }

    while (root != NULL)
    {
        length++;
        root = root->next;
    }

    return length;
}