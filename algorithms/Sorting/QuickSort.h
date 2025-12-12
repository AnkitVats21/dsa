#pragma once
#include "../../base/Solution.h"

class QuickSort : public Solution {
private:
    std::vector<int> data;

public:
    void loadInput(const InputData& input) override {
        data = input.arr;
    }

    void solve() override;

private:
    int partition(int low, int high);
    void quickSort(int low, int high);
};
