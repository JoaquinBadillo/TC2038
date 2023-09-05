#ifndef MERGESORT_H
#define MERGESORT_H

#include <vector>

using namespace std;

vector<int> mergeSort(vector<int> &data);
vector<int> doMergeSort(vector<int> &data, int start, int end);
vector<int> merge(vector<int> &left, vector<int> &right);

// MergeSort wrapper
vector<int> mergeSort(vector<int> &data) {
    return doMergeSort(data, 0, data.size() - 1);
}

// MergeSort implementation that doesn't modify the original vector (it returns a sorted copy)
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

vector<int> merge(vector<int> &left, vector<int> &right) {
    vector<int> res;

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

    // If left isn't traversed push the remaining elements.
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