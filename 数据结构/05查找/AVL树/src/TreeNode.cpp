#include "TreeNode.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

/* 获取当前节点高度 */
int get_height(TreeNode *node) {
  // 空节点高度为 1
  return node == nullptr ? -1 : node->height;
}

/* 更新节点高度 */
void update_height(TreeNode *node) {
  // 当前节点高度 = 最高子树高度 + 1
  node->height = max(get_height(node->left), get_height(node->right)) + 1;
}

/* 计算平衡因子 */
int get_balanced_factor(TreeNode *node) {
  if (node == nullptr) {
    return 0;
  }

  // 左子树高度 - 右子树高度
  return get_height(node->left) - get_height(node->right);
}

/* LL：右旋-旋转最右边的 */
TreeNode *rotate_right(TreeNode *node) {
  TreeNode *child = node->left;
  // 右旋与右孩冲突，右孩就变左孩
  TreeNode *grandchild = child->right;
  // 以 child 为原点，将 node 右旋
  child->right = node;
  node->left = grandchild;
  // 更新节点高度
  update_height(node);
  update_height(child);
  // 返回旋转后子树的根节点：因为可能要和原来与 node 的父节点重新连接
  return child;
}

/* RR：左旋-旋转最左边的 */
TreeNode *rotate_left(TreeNode *node) {
  TreeNode *child = node->right;
  TreeNode *grandchild = child->left;

  child->left = node;
  node->right = grandchild;

  update_height(node);
  update_height(child);

  return child;
}

/* 旋转 */
TreeNode *rotate(TreeNode *node) {
  int balanced_factor = get_balanced_factor(node);

  // L? 型
  if (balanced_factor > 1) {
    // LL 型，直接右旋
    if (get_balanced_factor(node->left) >= 0) {
      return rotate_right(node);
    }
    // LR 型，先左旋再右旋
    else {
      node->left = rotate_left(node->left);
      return rotate_right(node);
    }
  }

  // R? 型
  if (balanced_factor < -1) {
    // RR 型，直接左旋
    if (get_balanced_factor(node->right) <= 0) {
      return rotate_left(node);
    }
    // RL 型，先右旋再左旋
    else {
      node->right = rotate_right(node->right);
      return rotate_left(node);
    }
  }

  return node;
}

/* 中序遍历 */
void in_order(TreeNode *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}