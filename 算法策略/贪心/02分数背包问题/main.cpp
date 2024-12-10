#include "fractional_knapsack.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> wgt = { 20, 40, 10, 30, 50 };
    vector<int> val = { 120, 210, 50, 150, 240 };
    int cap = 50;
    double res = fractionalKnapsack(wgt, val, cap);

    cout << "最大价值为：" << res << endl;

    return 0;
}