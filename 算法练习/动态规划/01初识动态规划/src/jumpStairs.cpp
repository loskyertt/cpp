#include "jumpStairs.hpp"
#include <vector>

void backtrack(vector<int>& choices, int state, int n, vector<int>& res)
{
    // 当爬到第 n 阶时，方案数量加 1
    if (state == n) {
        res[0]++;
    }
    // 遍历所有选择
    for (auto& choice : choices) {
        // 剪枝：不允许越过第 n 阶
        if (state + choice > n) {
            continue;
        }
        backtrack(choices, choice + state, n, res);
    }
}

int jumpStairs(int n)
{
    vector<int> choices = { 1, 2 };
    int state = 0;
    vector<int> res = { 0 };
    backtrack(choices, state, n, res);
    return res[0];
}

int dfs(int i)
{
    // 已知 dp[1] 和 dp[2]
    if (i == 1 || i == 2) {
        return i;
    }
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1) + dfs(i - 2);
    return count;
}

int jumpStairsDFS(int n)
{
    return dfs(n);
}

int dfs(int i, vector<int>& mem)
{
    if (i == 1 || i == 2) {
        return i;
    }
    if (mem[i] != -1) {
        return mem[i];
    }
    // dp[i] = dp[i-1] + dp[i-2]
    int count = dfs(i - 1, mem) + dfs(i - 2, mem);
    return count;
}

int jumpStairsDFSMem(int n)
{
    vector<int> mem(n + 1, -1);
    return dfs(n, mem);
}

int jumpStairsDP(int n)
{
    if (n == 1 || n == 2)
        return n;
    vector<int> dp(n + 1);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

int jumpStairsDPComp(int n)
{
    if (n == 1 || n == 2) {
        return n;
    }
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int temp = b;
        b = a + b;
        a = temp;
    }
    return b;
}