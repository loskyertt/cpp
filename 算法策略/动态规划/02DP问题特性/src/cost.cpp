#include "cost.hpp"
#include <algorithm>
#include <vector>

int minCostClimbingStairsDP(vector<int>& cost)
{
    int n = cost.size() - 1;
    if (n == 1 || n == 2)
        return cost[n];
    // 初始化 dp 表，用于存储子问题的解
    vector<int> dp(n + 1);
    // 初始状态：预设最小子问题的解
    dp[1] = cost[1];
    dp[2] = cost[2];
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i];
    }
    return dp[n];
}

int climbingStairsConstraintDP(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }
    // 初始化 dp 表，用于存储子问题的解
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    // 初始状态：预设最小子问题的解
    dp[1][1] = 1; // 表示跳到第1阶且最后一步跳1阶的方案数。因为只能跳1阶，所以是1种方案
    dp[1][2] = 0; // 表示跳到第1阶且最后一步跳2阶的方案数。这是不可能的（因为总共只有1阶），所以是0种方案
    dp[2][1] = 0; // 表示跳到第2阶且最后一步跳1阶的方案数。虽然可以跳两个1阶到达第2阶，但是题目要求不能连续跳1阶，所以这种方案是不允许的，因此是0种方案
    dp[2][2] = 1; // 表示跳到第2阶且最后一步跳2阶的方案数。直接跳一个2阶就能到达，所以是1种方案
    // 状态转移：从较小子问题逐步求解较大子问题
    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i - 1][2];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
    }
    return dp[n][1] + dp[n][2];
}