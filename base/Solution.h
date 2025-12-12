#pragma once
#include <vector>

struct InputData {
    std::vector<int> arr;
};

class Solution {
public:
    virtual void loadInput(const InputData& input) = 0;
    virtual void solve() = 0;
    virtual ~Solution() = default;
};
