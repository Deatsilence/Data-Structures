#include <iostream>
#include <stdio.h>
#include <typeinfo>
#include <cstdlib>
#include <cmath>
// #include <format>

using namespace std;

void *checkedAllocate(size_t);
void DisplayArray(int *, size_t);
void InitializeOfArray(int *, size_t);
void AddItemToArray(int *, int, int, int);

int main()
{
    int n, secondN;
    int *pd;

    while (n != -1)
    {
        cout << "How many elements do you require?: ";
        cin >> n;

        pd = (int *)checkedAllocate(n);
        InitializeOfArray(pd, n);
        DisplayArray(pd, n);

        cout << "How many elements do you new require?: ";
        cin >> secondN;

        pd = (int *)realloc(pd, sizeof(int) * secondN);
        InitializeOfArray(pd, secondN - n);
        DisplayArray(pd, secondN);
    }

    delete pd; // or you should use free(pd);

    return 0;
}

void *checkedAllocate(size_t n)
{
    void *pd;
    if (n >= 0)
    {
        // pd = (int *)calloc(n, sizeof(int)); // initialize 0
        pd = (int *)malloc(sizeof(int) * n);

        if (!pd)
        {
            cout << "Cannot allocate memory" << endl;
            exit(EXIT_FAILURE);
        }
    }
    return pd;
}
void DisplayArray(int *pd, size_t n)
{
    for (int i = 0; i < n; i++)
        cout << "pd[" << i << "]: " << *(pd + i) << endl;
    cout << "--" << endl;
}
void InitializeOfArray(int *pd, size_t n)
{
    for (int i = 0; i < n; i++)
        *(pd + i) = i;
}