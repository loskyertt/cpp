#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
};

/* 构建二叉树：分治 */
TreeNode* dfs(vector<int>& preorder, unordered_map<int, int>& inorderMap, int i, int l, int r);

/* 构建二叉树 */
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder);