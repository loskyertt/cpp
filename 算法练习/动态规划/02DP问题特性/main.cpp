#include "cost.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> cost = { 0, 1, 10, 1 };
    int min_cost = minCostClimbingStairsDP(cost);

    cout << "最小花费是：" << min_cost << endl;

    return 0;
}