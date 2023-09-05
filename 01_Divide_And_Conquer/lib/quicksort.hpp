/* 
  QuickSort Header File
 
  Contains functions to sort a vector of integers using the 
  QuickSort algorithm to return a sorted copy.
 
  Author: Joaquín Badillo A0102634
  Last update: 04/Sept/2023
*/

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

using namespace std;


vector<int> quickSort(vector<int> data);
vector<int> doQuickSort(vector<int> &data, int start, int end);

/* 
  QuickSort Wrapper
  Gets the vector by value and returns the sorted copy
  It also abstracts the recursive calls from the user
 
  Params:
  vector<int> data: vector to be sorted
 
  Returns:
  vector<int>: sorted copy of the vector
 
  Time Complexity:
  O(n log n) in average case
  O(n^2) in worst case
*/
vector<int> quickSort(vector<int> data) {
    // Check if data is trivially sorted, otherwise sort it
    if (data.size() <= 1) return data;
    return doQuickSort(data, 0, data.size() - 1);
}

/* 
  QuickSort implementation
  Gets a vector by reference, sorts it and returns it.
  It also abstracts the recursive calls from the user.
  It uses the last element as the pivot.
 
  Params:
  vector<int> data: vector to be sorted
  int start: start index of the subarray to be sorted
  int end: end index of the subarray to be sorted
 
  Returns:
  vector<int>: sorted vector
 
  Time Complexity:
  O(n log n) in average case
  O(n^2) in worst case
*/
vector<int> doQuickSort(vector<int> &data, int start, int end) {
    int pivot = data[end];

    // Keeps track of the first element bigger than the pivot
    int i = start;

    // Partition: move all elements smaller than pivot to the left
    for (int j = start; j < end; j++) {
        if (data[j] <= pivot) {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
            i++;
        }
    }

    // Move pivot to its correct position (swap pivot with ith element)
    int temp = data[i];
    data[i] = data[end];
    data[end] = temp;

    // Recursively sort the left and right subarrays
    if (start < i - 1) doQuickSort(data, start, i - 1);
    if (i + 1 < end) doQuickSort(data, i + 1, end);

    return data;
}

#endif