#include "MergeSort.h"
#include "../Register.h"
#include <iostream>

REGISTER_ALGORITHM(MergeSort);

void MergeSort::solve() {
    if (data.empty()) return;
    mergeSort(0, data.size() - 1);

    for (int x : data) std::cout << x << " ";
    std::cout << "\n";
}

void MergeSort::mergeSort(int left, int right) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
}

void MergeSort::merge(int left, int mid, int right) {
    std::vector<int> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (data[i] < data[j])
            temp.push_back(data[i++]);
        else
            temp.push_back(data[j++]);
    }

    while (i <= mid) temp.push_back(data[i++]);
    while (j <= right) temp.push_back(data[j++]);

    for (int k = 0; k < temp.size(); ++k)
        data[left + k] = temp[k];
}
