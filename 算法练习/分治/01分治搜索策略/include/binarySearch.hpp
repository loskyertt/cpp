#pragma once

#include <vector>
using namespace std;

// 这种方式只能搜索按顺序排列的数组

/*二分查找：问题 f(i , j)*/
int dfs(vector<int>& nums, int target, int i, int j);

/*二分查找*/
int binarySearch(vector<int>& nums, int target);