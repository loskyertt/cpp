#include "permutations.hpp"
#include <vector>

void backtrack(vector<int>& state, const vector<int>& choices, vector<bool>& selected, vector<vector<int>>& res)
{
    if (state.size() == choices.size()) {
        res.push_back(state);
        return;
    }

    // 遍历所有选择
    for (int i = 0; i < choices.size(); i++) {
        int choice = choices[i];
        // 剪枝：不允许重复选择元素
        if (!selected[i]) {
            // 尝试：做出选择，更新状态
            selected[i] = true;
            state.push_back(choice);
            // 进行下一轮选择
            backtrack(state, choices, selected, res);
            // 回退：撤销选择，恢复到之前的状态
            selected[i] = false;
            state.pop_back();
        }
    }
}

vector<vector<int>> permutations(vector<int> nums)
{
    vector<int> state;
    vector<bool> selected(nums.size(), false);
    vector<vector<int>> res;
    backtrack(state, nums, selected, res);
    return res;
}