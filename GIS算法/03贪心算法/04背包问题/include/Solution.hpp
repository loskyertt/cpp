#pragma once
#include <vector>

/* 物品结构体 */
struct Item {
    double weight;
    double value;
    Item(double w, double val)
        : weight(w)
        , value(val)
    {
    }
};

class Solution {
public:
    static bool compare(Item a, Item b);

    /* 分数背包问题 */
    double fractionalKnapsack(double W, std::vector<Item>& items);
};