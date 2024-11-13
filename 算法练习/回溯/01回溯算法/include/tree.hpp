#pragma once

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

// 释放内存
void delete_tree(TreeNode* root);

// 前序遍历
void pre_order(TreeNode* root);

// 打印值
void print_val();