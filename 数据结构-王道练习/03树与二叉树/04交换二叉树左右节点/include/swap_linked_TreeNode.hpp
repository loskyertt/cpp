#pragma once

/* 链式存储的交换方法 */

struct TreeNode {
  int var;
  TreeNode *left, *right;
  TreeNode(int x) : var(x), left(nullptr), right(nullptr) {}
};

/* 交换二叉树的所有左、右子树，空的也要交换：递归实现 */
void swap_left_and_right(TreeNode *root);

/* 交换二叉树的所有左、右子树，空的也要交换：迭代实现 */
void swap_left_and_right_iteration(TreeNode *root);

/* BFS 打印二叉树 */
void bfs(TreeNode *root);

/* 前序遍历 */
void pre_order(TreeNode *root);

/* 中序遍历*/
void in_order(TreeNode *root);