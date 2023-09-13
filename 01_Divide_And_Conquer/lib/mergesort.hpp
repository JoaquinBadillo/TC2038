/*
  MergeSort Header File

  Contains functions to sort a std::vector of integers using the
  MergeSort algorithm to return a sorted copy.

  Author: Joaquín Badillo A0102634
  Last update: 04/Sept/2023
*/

#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

std::vector<int> mergeSort(const std::vector<int> &data);
std::vector<int> doMergeSort(const std::vector<int> &data, int start, int end);
std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right);

/*
  MergeSort Wrapper
  Gets the std::vector by reference and returns a sorted copy.
  It also abstracts the recursive calls from the user.

  Params:
  std::vector<int> data: std::vector to be sorted

  Returns:
  std::vector<int>: sorted copy of the std::vector

  Time Complexity:
  O(n log n)
*/
std::vector<int> mergeSort(const std::vector<int> &data) {
  return doMergeSort(data, 0, data.size() - 1);
}

/*
  MergeSort implementation
  Gets a std::vector by reference and returns a sorted copy.
  It does not modify the original std::vector.

  Params:
  std::vector<int> data: std::vector to be sorted
  int start: start index of the subarray to be sorted
  int end: end index of the subarray to be sorted

  Returns:
  std::vector<int>: sorted copy of the std::vector

  Time Complexity:
  O(n log n)
*/
std::vector<int> doMergeSort(const std::vector<int> &data, int start, int end) {
  // Slight modification to return std::vector
  if (start > end)
    return {};
  if (start == end)
    return {data[start]};

  int mid = start + (end - start) / 2;

  // Recursively sort the left and right subarrays
  std::vector<int> left = doMergeSort(data, start, mid);
  std::vector<int> right = doMergeSort(data, mid + 1, end);

  // Merge and return the sorted subarrays
  return merge(left, right);
}

/*
  Merge Procedure
  Combines two sorted std::vectors into a single sorted std::vector.

  Params:
  std::vector<int> left: sorted left half
  std::vector<int> right: sorted right half

  Returns:
  std::vector<int>: sorted std::vector containing the elements of left and right

  Time Complexity:
  O(n)
*/
std::vector<int> merge(const std::vector<int> &left,
                       const std::vector<int> &right) {
  std::vector<int> res;

  // Left and right iterators
  auto li = left.begin();
  auto ri = right.begin();

  // Push to result (res) std::vector the smallest element from left and right
  while ((li != left.end()) && (ri != right.end())) {
    if (*li <= *ri) {
      res.push_back(*li);
      li++;
    } else {
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
