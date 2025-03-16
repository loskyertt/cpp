#include "iteration.hpp"
#include <stdexcept>

using namespace std;

/* 插入节点：迭代插入 */
TreeNode *insert_iteration(TreeNode *node, int target) {
  if (!node) {
    node = new TreeNode(target);
    return node;
  }

  TreeNode *new_node = new TreeNode(target);
  TreeNode *prev = nullptr, *curr = node;

  while (curr) {
    if (curr->val == target) {
      // 重复节点不插入，直接返回
      return node;
    }
    prev = curr;
    if (curr->val < target) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }

  if (prev->val < target) {
    prev->right = new_node;
  } else {
    prev->left = new_node;
  }

  // 每插入一个节点都要更新下当前节点高度
  update_height(node);
  // 执行旋转操作，让该子树重新恢复平衡
  node = rotate(node);

  return node;
}

/* 删除节点：迭代删除 */
TreeNode *remove_iteration(TreeNode *node, int target) {
  if (!node) {
    throw out_of_range("节点为空！");
  }

  TreeNode *prev = nullptr, *curr = node;

  while (curr) {
    if (curr->val == target) {
      break;
    }
    prev = curr;
    if (curr->val < target) {
      curr = curr->right;
    } else {
      curr = curr->left;
    }
  }

  if (!curr) {
    throw out_of_range("没有这个节点！");
  }

  if (curr->left == nullptr || curr->right == nullptr) {
    TreeNode *child = curr->left != nullptr ? curr->left : curr->right;
    if (curr != node) {
      if (prev->left == curr) {
        prev->left = child;
      } else {
        prev->right = child;
      }
    } else {
      node = child;
    }
    delete curr;
  } else {
    TreeNode *tmp = curr->right;
    while (tmp->left) {
      tmp = tmp->left;
    }
    int tmp_val = tmp->val;
    // 下面两种写法都可行
    curr->right = remove_iteration(curr->right, tmp_val);
    // remove_iteration(curr, tmp_val);
    curr->val = tmp_val;
  }

  update_height(node);
  rotate(node);

  return node;
}