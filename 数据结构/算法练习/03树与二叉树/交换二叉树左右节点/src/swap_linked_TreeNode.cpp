#include "swap_linked_TreeNode.hpp"
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

/* 交换二叉树的所有左、右子树，空的也要交换 */
void swap_left_and_right(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  // TreeNode *left_node = root->left;
  // TreeNode *right_node = root->right;
  // root->left = right_node;
  // root->right = left_node;
  // 直接用标准库的函数实现交换
  swap(root->left, root->right);

  swap_left_and_right(root->left);
  swap_left_and_right(root->right);
}

/* BFS 打印二叉树 */
void bfs(TreeNode *root) {

  if (root == nullptr)
    return;

  queue<TreeNode *> queue;
  queue.push(root);

  while (!queue.empty()) {
    TreeNode *node = queue.front();
    queue.pop();

    if (node->left != nullptr) {
      queue.push(node->left);
    }
    if (node->right != nullptr) {
      queue.push(node->right);
    }
    cout << node->var << " ";
  }

  cout << endl;
}

/* 前序遍历 */
void pre_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  cout << root->var << " ";
  pre_order(root->left);
  pre_order(root->right);
}