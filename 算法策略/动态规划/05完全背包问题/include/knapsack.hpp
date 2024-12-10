#pragma once

#include <vector>

using namespace std;

/* 完全背包：空间优化后的动态规划 */
int unboundedKnapsackDP(vector<int>& wgt, vector<int>& val, int cap);

/* 零钱兑换：动态规划 */
int coinChangeDP(vector<int>& coins, int amt);

/* 零钱兑换 II：动态规划 */
int coinChangeIIDP(vector<int>& coins, int amt);
