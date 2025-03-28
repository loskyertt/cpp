#pragma once

/* 二叉树节点结构体 */
struct TreeNode {
  int val;         // 节点值
  TreeNode *left;  // 左子节点指针
  TreeNode *right; // 右子节点指针
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 释放节点 */
void free_tree_node(TreeNode *root);

/* 求二叉树最大深度 */
int max_depth(TreeNode *root);

/* 求二叉树叶子节点个数 */
int leaf_count(TreeNode *root);