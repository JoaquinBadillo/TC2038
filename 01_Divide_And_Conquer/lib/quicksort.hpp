#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using namespace std;

vector<int> quickSort(vector<int> data);
vector<int> doQuickSort(vector<int> &data, int start, int end);

// QuickSort wrapper, gets the vector by value and returns the sorted copy
vector<int> quickSort(vector<int> data) {
    if (data.size() <= 1) return data;
    return doQuickSort(data, 0, data.size() - 1);
}

// QuickSort using last element as pivot
vector<int> doQuickSort(vector<int> &data, int start, int end) {
    int pivot = data[end];

    int i = start;

    for (int j = start; j < end; j++) {
        if (data[j] <= pivot) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
        }
    }

    int temp = data[i];
    data[i] = data[end];
    data[end] = temp;

    if (start < i - 1) doQuickSort(data, start, i - 1);
    if (i + 1 < end) doQuickSort(data, i + 1, end);

    return data;
}

#endif