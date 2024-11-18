#pragma once

#include <vector>
using namespace std;

/* 0-1 背包：暴力搜索 */
int knapsackDFS(vector<int>& wgt, vector<int>& val, int i, int c);

/* 0-1背包：记忆化搜索 */
int knapsackDFSMem(vector<int>& wgt, vector<int>& val, vector<vector<int>>& mem, int i, int c);

/* 0-1背包：动态规划 */
int knapsackDP(vector<int>& wgt, vector<int>& val, int cap);