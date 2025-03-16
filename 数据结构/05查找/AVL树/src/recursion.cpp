#include "recursion.hpp"
#include <stdexcept>

using namespace std;

/* 插入节点：递归插入 */
TreeNode *insert_recursion(TreeNode *node, int target) {
  if (!node) {
    node = new TreeNode(target);
    return node;
  }

  if (node->val == target) {
    // 重复节点不插入，直接返回
    return node;
  }

  if (node->val < target) {
    // 这里左式的 node->right 相当于是 prev 前驱节点
    node->right = insert_recursion(node->right, target);
  } else {
    node->left = insert_recursion(node->left, target);
  }

  // 每插入一个节点都要更新下当前节点高度
  update_height(node);
  // 执行旋转操作，让该子树重新恢复平衡
  node = rotate(node);

  return node;
}

/* 删除节点：递归删除 */
TreeNode *remove_recursion(TreeNode *node, int target) {
  if (!node) {
    throw out_of_range("节点为空！");
  }

  if (node->val < target) {
    // 这里左式的 node->right 相当于是 prev 前驱节点
    node->right = remove_recursion(node->right, target);
  } else if (node->val > target) {
    node->left = remove_recursion(node->left, target);
  } else {
    // 如果子树为 0 || 1
    if (node->left == nullptr || node->right == nullptr) {
      TreeNode *child = node->left != nullptr ? node->left : node->right;
      if (child == nullptr) {
        delete node;
        return nullptr;
      } else {
        delete node;
        node = child;
      }
    } else {
      TreeNode *tmp = node->right;
      while (tmp->left) {
        tmp = tmp->left;
      }
      int tmp_val = tmp->val;
      node->right = remove_recursion(node->right, tmp_val);
      node->val = tmp_val;
    }
  }

  update_height(node);
  rotate(node);

  return node;
}