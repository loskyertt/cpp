#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <utility>

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

/* 求二叉树高度，非递归方式 */
int get_height(TreeNode *root) {
  if (!root) {
    return 0;
  }

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  int height = 1;
  while (!q.empty()) {
    auto [node, level] = q.front();
    q.pop();
    height = max(height, level);

    if (node->left) {
      q.push({node->left, level + 1});
    }
    if (node->right) {
      q.push({node->right, level + 1});
    }
  }

  return height;
}

/* 求二叉树高度，递归方式 */
int get_height_recursion(TreeNode *root) {
  if (!root) {
    return 0;
  }

  // 树的高度 = max(左子树的高度, 右子树的高度) + 根节点的高度（即 1）
  return 1 + max(get_height_recursion(root->left),
                 get_height_recursion(root->right));
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  int height = get_height(root);

  cout << "二叉树高度为（迭代实现）：" << height << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  int height = get_height_recursion(root);

  cout << "二叉树高度为（递归实现）：" << height << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}