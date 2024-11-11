#include "frogJump.hpp"
#include <vector>

using namespace std;

int frog_jump(int n)
{
    // 基本情况
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 1;
    }

    // 初始化 dp 数组
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;

    // 计算每个台阶的跳法数量
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    // 返回到达第 n 级台阶的跳法数量
    return dp[n];
}