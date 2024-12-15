#pragma once

#include <vector>
struct Drink {
    int satisfaction; // 满意度
    int amount; // 可用的饮料量
};

class Solution {
public:
    static bool compare(Drink a, Drink b);

    void distribute(std::vector<Drink>& drinks, int target);
};