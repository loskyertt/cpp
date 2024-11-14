#include "subsetSumI.hpp"
#include <algorithm>
#include <vector>

void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res)
{
    // 子集和等于 target 时，记录解
    if (target == 0) {
        res.push_back(state);
    }
    // 遍历所有选择
    // 剪枝：从 start 开始遍历，避免产生重复子集
    for (int i = start; i < choices.size(); i++) {
        // 剪枝：若子集和超过 target，则直接结束循环
        // 这是因为数组已排序，后边元素更大，子集和一定超过 target
        if (target - choices[i] < 0) {
            break;
        }
        // 尝试：做出选择，更新 target, start
        state.push_back(choices[i]);
        // 进行下一轮选择
        backtrack(state, target - choices[i], choices, i, res);
        // 回退：撤销选择，恢复到之前的状态
        state.pop_back();
    }
}

vector<vector<int>> subsetSumI(vector<int>& nums, int target)
{
    vector<int> state; // 状态（子集）
    sort(nums.begin(), nums.end());
    int start = 0;
    vector<vector<int>> res;
    backtrack(state, target, nums, start, res);
    return res;
}