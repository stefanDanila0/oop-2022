#pragma once

class Sort
{
    int* arr;
    unsigned arr_no;
public:
    Sort();
    Sort(int min, int max, unsigned arr_no);
    Sort(int* arr, unsigned arr_no);
    Sort(unsigned arr_no, ...);
    Sort(const char* array);
    ~Sort();
    void InsertSort(bool ascendent);
    int partition(int array[], int low, int high, bool ascendent);
    void quick(int array[], int low, int high, bool ascendent);
    void QuickSort(bool ascendent);
    void BubbleSort(bool ascendent);
    void Print() const;
    unsigned int  GetElementsCount() const;
    int  GetElementFromIndex(unsigned index) const;
};