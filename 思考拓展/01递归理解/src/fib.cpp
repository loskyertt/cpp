#include "fib.hpp"
#include <vector>

int fib(int n)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

// 注意要把 mem 设置为全局变量（在递归函数之外）
int fib_mem(int n, std::vector<int>& mem)
{
    if (n == 1 || n == 2) {
        return 1;
    }

    if (mem[n] != 0) {
        return mem[n];
    }

    mem[n] = fib_mem(n - 1, mem) + fib_mem(n - 2, mem);

    return mem[n];
}

int fib_dp(int n)
{
    std::vector<int> dp(n + 1, 0);
    dp[1] = 1;
    dp[2] = 1;

    for (int i = 3; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}