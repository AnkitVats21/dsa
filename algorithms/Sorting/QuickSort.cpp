#include "QuickSort.h"
#include "../Register.h"
#include <iostream>

REGISTER_ALGORITHM(QuickSort);

void QuickSort::solve() {
    if (data.empty()) return;
    quickSort(0, data.size() - 1);

    for (int x : data) std::cout << x << " ";
    std::cout << "\n";
}

void QuickSort::quickSort(int low, int high) {
    if (low < high) {
        int p = partition(low, high);
        quickSort(low, p - 1);
        quickSort(p + 1, high);
    }
}

int QuickSort::partition(int low, int high) {
    int pivot = data[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (data[j] < pivot)
            std::swap(data[++i], data[j]);
    }
    std::swap(data[i + 1], data[high]);
    return i + 1;
}
