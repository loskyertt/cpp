#ifndef __SOLUTION_H__
#define __SOLUTION_H__

#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x)
        : val(x)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

/* 回溯算法框架 */
class Solution {
public:
    /* 判断当前状态是否为解 */
    bool isSolution(vector<TreeNode*>& state);
    /* 记录解 */
    void recordSolution(vector<TreeNode*>& state, vector<vector<TreeNode*>>& res);
    /* 判断在当前状态下，该选择是否合法 */
    bool isValid(vector<TreeNode*>& state, TreeNode* choice);
    /* 更新状态 */
    void makeChoice(vector<TreeNode*>& state, TreeNode* choice);
    /* 恢复状态 */
    void undoChoice(vector<TreeNode*>& state, TreeNode* choice);
    /* 算法示例 */
    void backtrack(vector<TreeNode*>& state, vector<TreeNode*>& choices, vector<vector<TreeNode*>>& res);
};

#endif // __SOLUTION_H__