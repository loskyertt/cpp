#pragma once

#include <vector>

using namespace std;

/* 物品 */
class Item {
public:
    int w; // 物品重量
    int v; // 物品价值

    Item(int w, int v);
};

/* 分数背包：贪心 */
double fractionalKnapsack(vector<int>& wgt, vector<int>& val, int cap);