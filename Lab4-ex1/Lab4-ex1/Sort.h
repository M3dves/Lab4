#include <iostream>
#include <cstring>
#include <initializer_list>
#include <stdarg.h>

class Sort
{
    // add data members
    int cnt=0;
    int v[1000] = {0};
public:
    // add constuctors
    Sort(int nr, int mini, int maxi);
    Sort(std::initializer_list<int> x);
    Sort(int x[], int nr);
    Sort(int nr,...);
    Sort(char s[]);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
