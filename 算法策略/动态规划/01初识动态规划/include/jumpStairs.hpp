#pragma once

#include <vector>
using namespace std;

/* 方式一：*/
/* 回溯 */
void backtrack(vector<int>& choices, int state, int n, vector<int>& res);

/* 爬楼梯：回溯 */
int jumpStairs(int n);

/* 方式二：*/
/* 搜索 */
int dfs(int i);

/* 爬楼梯：搜索 */
int jumpStairsDFS(int n);

/* 方式三：*/
/* 记忆化搜索 */
int dfs(int i, vector<int>& mem);

/* 爬楼梯：记忆化搜索*/
int jumpStairsDFSMem(int n);

/* 方式四：*/
/* 爬楼梯：动态规划 */
int jumpStairsDP(int n);

/* 方式五：*/
/* 爬楼梯：空间优化后的动态规划 */
int jumpStairsDPComp(int n);