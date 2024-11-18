#pragma once

#include <vector>
using namespace std;

/* 方法一：暴力搜索 */
int minPathSumDFS(vector<vector<int>>& grid, int i, int j);

/* 方法二：记忆化搜索 */
int minPathSumDFSMem(vector<vector<int>>& grid, vector<vector<int>>& mem, int i, int j);

/* 方法三：动态规划 */
int minPathSumDP(vector<vector<int>>& grid);