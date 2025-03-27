#include <climits>
#include <iostream>
#include <queue>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 释放树的节点 */
// 先序遍历和中序遍历释放是不正确的！
void free_tree_node(TreeNode *root) {
  if (!root) {
    return;
  }

  free_tree_node(root->left);
  free_tree_node(root->right);

  delete root;
}

/* 判断二叉树是否是完全二叉树 */
bool is_complete_binary_tree(TreeNode *root) {
  if (!root) {
    return true;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    // 如果当前节点为空，那它后续的节点必须都为空才能说明是完全二叉树
    if (node == nullptr) {
      while (!q.empty()) {
        TreeNode *temp = q.front();
        if (temp) {
          return false;
        }
        q.pop();
      }
      // 最后队列中的节点就弹出完了，说明后续所有节点都是空节点，可以直接退出循环
      break;
    } else {
      q.push(node->left);
      q.push(node->right);
    }
  }

  return true;
}

/* 判断二叉树是否是完全二叉树：改进实现，使用 flag */
bool is_complete_binary_tree_improved(TreeNode *root) {
  if (!root) {
    return true;
  }

  queue<TreeNode *> q;
  q.push(root);

  bool flag = false; // 为 true 的话，表示遇到了空节点
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    // 如果遇到了空节点，且当前节点不是空节点，那么就说明不是完全二叉树
    if (flag && node) {
      return false;
    }

    if (node) {
      q.push(node->left);
      q.push(node->right);
    } else {
      // 遇到空节点，就把 flag 标记为 true，用于后续的判断
      flag = true;
    }
  }

  return true;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  if (is_complete_binary_tree(root)) {
    cout << "是完全二叉树！" << endl;
  } else {
    cout << "不是！" << endl;
  }

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  if (is_complete_binary_tree(root)) {
    cout << "是完全二叉树！" << endl;
  } else {
    cout << "不是！" << endl;
  }

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}