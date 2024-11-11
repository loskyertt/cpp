#include <iostream>
#include <vector>
using namespace std;

// 0-1背包问题动态规划实现
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int n)
{
    // 创建二维DP数组
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // 填充DP表
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i - 1] <= w) { // 当前物品可以放入背包
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else { // 当前物品不能放入背包
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // 返回最大价值
    return dp[n][W];
}

int main()
{
    int n, W;
    cout << "请输入物品数量 n 和背包容量 W: ";
    cin >> n >> W;

    vector<int> weights(n), values(n);
    cout << "请输入每个物品的重量和价值 (weight value):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> weights[i] >> values[i];
    }

    int maxValue = knapsack(W, weights, values, n);
    cout << "背包中可以达到的最大价值为: " << maxValue << endl;

    return 0;
}
