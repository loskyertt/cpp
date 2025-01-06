#include "Solution.hpp"
#include <vector>

bool Solution::isSolution(vector<TreeNode*>& state)
{
    return !state.empty() && state.back()->val == 7;
}

void Solution::recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res)
{
    res.push_back(state);
}

bool Solution::isValid(vector<TreeNode*>& state, TreeNode* choice)
{
    return choice != nullptr && choice->val != 3;
}

void Solution::makeChoice(vector<TreeNode*>& state, TreeNode* choice)
{
    state.push_back(choice);
}

void Solution::undoChoice(vector<TreeNode*>& state, TreeNode* choice)
{
    state.pop_back();
}

void Solution::backtrack(vector<TreeNode*>& state, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res)
{
    // 检查是否为解
    if (isSolution(state)) {
        // 记录解
        recordSolution(state, res);
    }

    // 遍历所有选择
    for (TreeNode* choice : choices) {
        // 剪枝：检查选择是否合法
        if (isValid(state, choice)) {
            // 尝试：做出选择，更新状态
            makeChoice(state, choice);
            // 进行下一轮选择
            vector<TreeNode*> nextChoices { choice->left, choice->right };
            backtrack(state, nextChoices, res);
            // 回退：撤销选择，恢复到之前的状态
            undoChoice(state, choice);
        }
    }
}
