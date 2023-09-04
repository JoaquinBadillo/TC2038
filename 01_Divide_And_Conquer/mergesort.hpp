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

// MergeSort implementation that doesn't modify the original vector
vector<int> doMergeSort(vector<int> &data, int start, int end) {
    if (start > end) return {};

    if (start == end) return {data[start]};

    int mid = start + (end - start) / 2;

    vector<int> left = doMergeSort(data, start, mid);
    vector<int> right = doMergeSort(data, mid + 1, end);

    return merge(left, right);
}

vector<int> merge(vector<int> &left, vector<int> &right) {
    vector<int> res;

    auto li = left.begin();
    auto ri = right.begin();

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

    while (li != left.end()) {
        res.push_back(*li);
        li++;
    }

    while (ri != right.end()) {
        res.push_back(*ri);
        ri++;
    }

    return res;
}


#endif