#include <iostream>
#include <string>
#include "single_linked_list.hpp"
// #include "stack.hpp"
// #include "queue.hpp"

using namespace std;

// O(N)
void PrintArray(int *array, unsigned int N)
{
    for (int i = 0; i < N; i++)  // N
        cout << array[i] << " "; // N * 1
                                 // O(2N) -> O(N)
    cout << endl;
}
// O(N)
bool LinearSearch(int *array, unsigned int N, int soughtValue)
{
    for (int i = 0; i < N; i++) // N
    {
        if (array[i] == soughtValue) // N * 1 -> N
        {
            cout << endl
                 << "soughtValue found in index " << i << endl; // 1
            return true;                                        // 1
        }
    }
    // T(2N + 2) -> O(N)

    cout << endl
         << "soughtValue not found in Array " << endl; // 1
    return false;                                      // 1

    // T(2N + 2) -> O(N)
}
// O(logN)
int BinarySearch(int *array, int data, int low, int high)
{
    static int s_stepCounter{0};
    s_stepCounter++;
    // -5, 1, 23, 24, 53, 94, 123, 542
    if (low <= high) // 1
    {
        int mid = low + ((high - low) / 2); // logN

        // If found at mid, then return mid
        if (data == array[mid]) //
        {
            cout << "Sought value found in " << s_stepCounter << " steps" << endl;
            return mid;
        }
        // Search the left part
        if (data < array[mid])
            return BinarySearch(array, data, low, mid - 1); // mid - 1 high value of the left part
        // Search the right part
        if (data > array[mid])
            return BinarySearch(array, data, mid + 1, high); // mid + 1 low value of the right part
    }
    s_stepCounter = 0;
    cout << "Sought value not found in " << endl;
    return -1;
}
// O(N^2)
void BubbleSort(int *array, unsigned int N)
{
    // 24, 23, 53, 94, -5, 123, 1
    unsigned int i, j; // 2
    int temp{0};       // 1

    for (i = 0; i < N; i++) // N
    {
        for (j = 0; j < N - 1; j++) // N * (N - 1) -> N^2 - N
        {
            if (array[j] > array[j + 1]) // (N^2 - N) * 1
            {
                int temp = array[j + 1]; // (N^2 - N) * 1
                array[j + 1] = array[j]; // (N^2 - N) * 1
                array[j] = temp;         // (N^2 - N) * 1
            }
        }
    }
    // T(N) = (5N^2 - 4N + 3) -> O(N) = O(N^2)
}

int main()
{
    Node *root;
    root = nullptr;

#pragma region Big - O(N) & T(N)

    /*
        O(1) -> Constant
        O(N) -> Linear
        O(N^2) -> Quadratic
        O(logN) -> Logarithmic
        O(NlogN) -> Linearithmic
        O(c^N) -> Exponential
        O(N!) -> Factorial

        N => Size of data set and c is constant a value
    */

#pragma region O(1) - Constant Complexity

    // const int N{5};
    // int myArray[N]{45, 23, 43, 2, -5};

    // // O(1) -> it's also the best case
    // cout << myArray[2] << endl; // or *(myArray + 2)
    // // O(1)

    // ////////////////////////////////////////////////

    // // O(1) -> it's also the best case
    // bool control = 6 % 2 == 0 ? true : false; // control = true // O(1)
    // cout << control << endl;

#pragma endregion

#pragma region O(N) - Linear Complexity

    // const int N{7};
    // int myArray[N]{24, 23, 53, 94, -5, 123, 1};

    // // O(N)
    // PrintArray(myArray, N);
    // // ////////////////////////////////////////////////

    // //// Linear Search
    // LinearSearch(myArray, N, 24); // Best Case
    // LinearSearch(myArray, N, 94); // Average Case
    // LinearSearch(myArray, N, 1);  // Worst Case
    // LinearSearch(myArray, N, 10); // Worst Case

#pragma endregion

#pragma region O(N ^ 2) - Quadratic Complexity

    // const int N{7};
    // int myArray[N]{24, 23, 53, 94, -5, 123, 1};
    // // 123 i , 1 i + 1
    // PrintArray(myArray, N);
    // BubbleSort(myArray, N);
    // PrintArray(myArray, N);

#pragma endregion

#pragma region O(logN) - Logarithmic Complexity

    // const int N{8};
    // int myArray[N]{24, 23, 53, 94, -5, 123, 1, 542};
    // BubbleSort(myArray, N);
    // PrintArray(myArray, N);

    // cout << "Sought Value found in " << BinarySearch(myArray, 53, 0, N - 1) << ". index" << endl;

#pragma endregion

#pragma endregion

#pragma region Single Linked List

    PrintLinkedList(root);

    root = AddToSingleLinkedList(root, 5);
    PrintLinkedList(root);

    // root = AddToSingleLinkedList(root, 7);
    // PrintLinkedList(root);

    // root = AddToSingleLinkedList(root, 2);
    // PrintLinkedList(root);

    // root = AddToSingleLinkedList(root, 44);
    // PrintLinkedList(root);

    // root = AddToIndexSingleLinkedList(root, 3, 88);
    // cout << "Length: " << LengthOfLinkedList(root) << endl;
    // PrintLinkedList(root);

    // root = AddToSingleLinkedList(root, 90);
    // PrintLinkedList(root);

    // root = DeleteFromSingleLinkedList(root, 5);
    // PrintLinkedList(root);

    // root = DeleteFromSingleLinkedList(root, 44);
    // PrintLinkedList(root);

    // root = DeleteFromSingleLinkedList(root, 2);
    // PrintLinkedList(root);

    // root = DeleteFromSingleLinkedList(root, 90);
    // PrintLinkedList(root);

    // root = DeleteFromSingleLinkedList(root, 7);
    // PrintLinkedList(root);

#pragma endregion

#pragma region Sorted Single Linked List

    // root = AddToSortedSingleLinkedList(root, 3);
    // PrintLinkedList(root);
    // root = AddToSortedSingleLinkedList(root, 8);
    // PrintLinkedList(root);
    // root = AddToSortedSingleLinkedList(root, 5);
    // PrintLinkedList(root);
    // root = AddToSortedSingleLinkedList(root, 7);
    // PrintLinkedList(root);
    // root = AddToSortedSingleLinkedList(root, 2);
    // PrintLinkedList(root);
    // root = DeleteFromSortedSingleLinkedList(root, 3);
    // PrintLinkedList(root);
    // root = DeleteFromSortedSingleLinkedList(root, 7);
    // PrintLinkedList(root);
    // root = DeleteFromSortedSingleLinkedList(root, 8);
    // PrintLinkedList(root);
    // root = DeleteFromSortedSingleLinkedList(root, 2);
    // PrintLinkedList(root);
    // root = DeleteFromSortedSingleLinkedList(root, 5);
    // PrintLinkedList(root);

#pragma endregion

#pragma region Stack(Linked List)

    // PrintStack(root);

    // root = Push(root, 55);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Push(root, 10);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Push(root, -24);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Pop(root);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Pop(root);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Pop(root);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Push(root, 1);
    // PrintStack(root);
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

    // root = Push(root, 85);
    // PrintStack(root);
    // cout << "Length of the stack:" << LengthOfStack(root) << endl;
    // cout << "Top:" << GetTop(root) << endl
    //      << endl;

#pragma endregion

#pragma region Queue(Linked List)

    // PrintQueue(root);

    // root = Enqueue(root, 55);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
   

    // root = Enqueue(root, 24);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);


    // root = Enqueue(root, -45);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
  

    // root = Dequeue(root);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
 

    // root = Dequeue(root);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
   

    // root = Dequeue(root);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
    

    // root = Enqueue(root, 100);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // PrintQueue(root);
   

    // root = Enqueue(root, 200);
    // cout << "Head: " << GetHead(root) << endl;
    // cout << "Rear: " << GetRear(root) << endl;
    // cout << "Length: " << LengthOfQueue(root) << endl;
    // PrintQueue(root);
    

#pragma endregion

    delete root;

    return 0;
}