#include "findFakeCoin.hpp"
#include <iostream>

int main()
{
    // 假设硬币中有一个伪币，伪币值为0，其他硬币值为1
    vector<int> coins = { 1, 1, 1, 1, 0, 1 };

    int n = coins.size();

    cout << "n = " << n << endl;

    int fakeCoinIndex = findFakeCoin(coins, 0, n - 1);
    cout << "伪币是第 " << fakeCoinIndex + 1 << " 个硬币。" << endl;

    return 0;
}
