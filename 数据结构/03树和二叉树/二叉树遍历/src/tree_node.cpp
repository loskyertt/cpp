#include "tree_node.hpp"
#include <algorithm>

using std::max;

/* 释放节点 */
void free_tree_node(TreeNode *root) {
  if (!root) {
    return;
  }

  free_tree_node(root->left);
  free_tree_node(root->right);

  delete root;
}

/* 求二叉树最大深度 */
int max_depth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int left_depth = max_depth(root->left);
  int right_depth = max_depth(root->right);

  return max(left_depth, right_depth) + 1;
}

/* 求二叉树叶子节点个数 */
int leaf_count(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  return leaf_count(root->left) + leaf_count(root->right);
}