#include "Item.hpp"
#include <iostream>

int main()
{
    vector<Item> items = { { 2, 40 }, { 3, 50 }, { 5, 100 }, { 7, 200 }, { 1, 10 } };
    int W = 10; // 背包容量

    int maxProfit = knapsack(W, items);
    cout << "0-1 背包问题的最大价值: " << maxProfit << endl;

    return 0;
}