#include <climits>
#include <iostream>
#include <queue>
#include <stdexcept>
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

/* 求二叉排序树中给定节点层次：递归实现 */
int get_depth_01(TreeNode *root, int target, int depth = 1) {
  if (!root) {
    throw out_of_range("树为空或没有目标节点！");
  }

  if (root->val == target) {
    return depth;
  } else if (root->val < target) {
    return get_depth_01(root->right, target, depth + 1);
  } else {
    return get_depth_01(root->left, target, depth + 1);
  }
}

/* 求二叉排序树中给定节点层次：迭代实现 */
int get_depth_02(TreeNode *root, int target) {
  if (!root) {
    throw out_of_range("树为空！");
  }

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();
    // 找到了就返回当前深度
    if (node->val == target) {
      return depth;
    }
    if (node->val < target && node->right) {

      q.push({node->right, depth + 1});
    }
    if (node->val > target && node->left) {
      q.push({node->left, depth + 1});
    }
  }

  throw out_of_range("没有目标节点！");
}

void test_01() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  int depth = get_depth_01(root, 20);
  cout << "目标节点层次为（递归实现）：" << depth << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  int depth = get_depth_02(root, 20);
  cout << "目标节点层次为（迭代实现）：" << depth << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}