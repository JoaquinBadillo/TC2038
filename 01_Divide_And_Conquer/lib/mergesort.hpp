/* 
  MergeSort Header File
 
  Contains functions to sort a vector of integers using the 
  MergeSort algorithm to return a sorted copy.
 
  Author: Joaquín Badillo A0102634
  Last update: 04/Sept/2023
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> &data);
vector<int> doMergeSort(vector<int> &data, int start, int end);
vector<int> merge(vector<int> &left, vector<int> &right);

/*
  MergeSort Wrapper
  Gets the vector by reference and returns a sorted copy.
  It also abstracts the recursive calls from the user.

  Params:
  vector<int> data: vector to be sorted

  Returns:
  vector<int>: sorted copy of the vector

  Time Complexity:
  O(n log n)
*/
vector<int> mergeSort(vector<int> &data) {
    return doMergeSort(data, 0, data.size() - 1);
}

/*
  MergeSort implementation
  Gets a vector by reference and returns a sorted copy.
  It does not modify the original vector.
  
  Params:
  vector<int> data: vector to be sorted
  int start: start index of the subarray to be sorted
  int end: end index of the subarray to be sorted

  Returns:
  vector<int>: sorted copy of the vector

  Time Complexity:
  O(n log n)
*/
vector<int> doMergeSort(vector<int> &data, int start, int end) {
    // Slight modification to return vector
    if (start > end) return {};
    if (start == end) return {data[start]};

    int mid = start + (end - start) / 2;

    // Recursively sort the left and right subarrays
    vector<int> left = doMergeSort(data, start, mid);
    vector<int> right = doMergeSort(data, mid + 1, end);

    // Merge and return the sorted subarrays
    return merge(left, right);
}

/*
  Merge Procedure
  Combines two sorted vectors into a single sorted vector.

  Params:
  vector<int> left: sorted left half
  vector<int> right: sorted right half

  Returns:
  vector<int>: sorted vector containing the elements of left and right

  Time Complexity:
  O(n)
*/
vector<int> merge(vector<int> &left, vector<int> &right) {
    vector<int> res;

    // Left and right iterators
    auto li = left.begin();
    auto ri = right.begin();

    // Push to result (res) vector the smallest element from left and right
    while ((li != left.end()) && (ri != right.end())) {
        if (*li <= *ri) {
            res.push_back(*li);
            li++;
        } 
        
        else {
            res.push_back(*ri);
            ri++;
        }
    }

    // If left isn't fully traversed, push the remaining elements.
    while (li != left.end()) {
        res.push_back(*li);
        li++;
    }

    // Otherwise, if right isn't fully traversed, push the remaining elements.
    while (ri != right.end()) {
        res.push_back(*ri);
        ri++;
    }

    return res;
}


#endif