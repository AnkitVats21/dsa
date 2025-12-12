#pragma once
#include "../../base/Solution.h"

class MergeSort : public Solution {
private:
    std::vector<int> data;

public:
    void loadInput(const InputData& input) override {
        data = input.arr;
    }

    void solve() override;

private:
    void mergeSort(int left, int right);
    void merge(int left, int mid, int right);
};
