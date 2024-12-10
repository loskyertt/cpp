#include "knapsack.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> wgt = { 2, 2, 4, 6, 3 };
    vector<int> val = { 3, 4, 8, 9, 6 };
    int c = 9;
    vector<vector<int>> mem(wgt.size() + 1, vector<int>(c + 1, -1));
    // int total_val = knapsackDFSMem(wgt, val, mem, wgt.size(), c);
    int total_val = knapsackDP(wgt, val, c);
    cout << "最大价值是：" << total_val << endl;

    return 0;
}