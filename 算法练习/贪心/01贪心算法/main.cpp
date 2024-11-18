#include "greedy.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> coins = { 1, 2, 5 };
    int amt = 11;
    int min_count = coinChangeGreedy(coins, amt);
    if (min_count != -1) {
        cout << "最少硬币数量：" << min_count << endl;
    } else {
        cout << "没有方案可选" << endl;
    }

    return 0;
}