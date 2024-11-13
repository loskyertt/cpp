#include "binarySearch.hpp"

int dfs(vector<int>& nums, int target, int i, int j)
{
    if (i > j) {
        return -1;
    }

    // 计算中点索引 m
    int m = (i + j) / 2;
    if (nums[m] < target) {
        // 递归子问题
        return dfs(nums, target, m + 1, j);
    } else if (nums[m] > target) {
        return dfs(nums, target, i, m - 1);
    } else {
        return m; // 找到目标元素，并返回索引
    }
}

int binarySearch(vector<int>& nums, int target)
{
    int n = nums.size();
    // 求解问题 f(0, n - 1)
    return dfs(nums, target, 0, n - 1);
}