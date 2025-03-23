#include "recursion.hpp"
#include <stdexcept>

using std::out_of_range;

/* 查找操作：递归实现 */
bool find_val_recursion(TreeNode *root, int target) {
  if (root == nullptr) {
    return false;
  }

  if (root->val < target) {
    return find_val_recursion(root->right, target);
  } else if (root->val > target) {
    return find_val_recursion(root->left, target);
  } else {
    return true;
  }
}

/* 插入节点：递归实现 */
TreeNode *insert_recursion(TreeNode *root, int target) {
  if (!root) {
    root = new TreeNode(target);
    return root;
  }

  if (root->val < target) {
    root->right = insert_recursion(root->right, target);
  } else if (root->val > target) {
    root->left = insert_recursion(root->left, target);
  } else {
    return root;
  }

  return root;
}

/* 递归操作实现 */
TreeNode *remove_recursion(TreeNode *root, int target) {
  if (!root) {
    throw out_of_range("树为空！");
  }

  if (root->val < target) {
    // 左边的 roo->right 相当于迭代实现中的 prev 前驱节点
    root->right = remove_recursion(root->right, target);
  } else if (root->val > target) {
    root->left = remove_recursion(root->left, target);
  } else {
    if (root->left == nullptr || root->right == nullptr) {
      TreeNode *child = root->left != nullptr ? root->left : root->right;
      if (!child) {
        delete root;
        return nullptr;
      } else {
        delete root;
        root = child;
      }
    } else {
      TreeNode *tmp = root->right;
      while (tmp->left) {
        tmp = tmp->left;
      }
      int tmp_val = tmp->val;
      root->right = remove_recursion(root->right, tmp_val);
      root->val = tmp_val;
    }
  }

  return root;
}