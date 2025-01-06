#include "Solution.hpp"
#include <iostream>

using namespace std;

int main()
{
    // 构造测试二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3); // 这个节点会被剪枝
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7); // 目标节点

    Solution solution;
    vector<TreeNode*> state;
    vector<TreeNode*> choices = { root };
    vector<vector<TreeNode*>> res;

    // 执行回溯算法
    solution.backtrack(state, choices, res);

    // 输出结果
    cout << "找到的有效路径：" << endl;
    for (const auto& path : res) {
        for (const auto& node : path) {
            cout << node->val << " ";
        }
        cout << endl;
    }

    // 释放内存
    delete root->left->right->right;
    delete root->left->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
