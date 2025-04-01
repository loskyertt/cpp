#include <climits>
#include <iostream>
#include <queue>
#include <tuple>

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

/* 判断是否是二叉搜索树：递归实现 */
bool is_binary_search_tree_01(TreeNode *root, int min_val = INT_MIN, int max_val = INT_MAX) {
  if (!root) {
    return true;
  }

  if (root->val <= min_val || root->val >= max_val) {
    return false;
  }

  return is_binary_search_tree_01(root->left, min_val, root->val) &&
         is_binary_search_tree_01(root->right, root->val, max_val);
}

/* 判断是否是二叉搜索树：迭代实现 */
bool is_binary_search_tree_02(TreeNode *root) {
  if (!root) {
    return true;
  }

  queue<tuple<TreeNode *, int, int>> q;
  q.push({root, INT_MIN, INT_MAX});

  while (!q.empty()) {
    auto [node, min_val, max_val] = q.front();
    q.pop();

    if (node->val <= min_val || node->val >= max_val) {
      return false;
    }

    if (node->left) {
      q.push({node->left, min_val, node->val});
    }
    if (node->right) {
      q.push({node->right, node->val, max_val});
    }
  }

  return true;
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

  cout << "递归实现判断：" << endl;
  if (is_binary_search_tree_01(root)) {
    cout << "是二叉搜索树！" << endl;
  } else {
    cout << "不是！" << endl;
  }

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

  cout << "迭代实现判断：" << endl;
  if (is_binary_search_tree_02(root)) {
    cout << "是二叉搜索树！" << endl;
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