#pragma once

/* 斐波那契：普通递归实现 */
#include <vector>
int fib(int n);

/* 斐波那契：记忆力搜索优化 */
int fib_mem(int n, std::vector<int>& mem);

/* 斐波那契：动态规划 */
int fib_dp(int n);