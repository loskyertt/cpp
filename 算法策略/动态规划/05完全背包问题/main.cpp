#include "knapsack.hpp"
#include <iostream>
#include <vector>

int main()
{
    // vector<int> wgt = { 1, 2, 3, 4 };
    // vector<int> val = { 2, 3, 4, 5 };
    // int cap = 6;
    // int total_val = unboundedKnapsackDP(wgt, val, cap);
    // cout << "最大价值为：" << total_val << endl;

    vector<int> coins = { 1, 2, 5 };
    int amt = 5;
    int toal_val = coinChangeIIDP(coins, amt);
    cout << "可组合的总数是：" << toal_val << endl;

    return 0;
}