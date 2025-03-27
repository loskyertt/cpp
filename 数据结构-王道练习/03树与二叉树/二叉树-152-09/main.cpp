#include <climits>
#include <iostream>
#include <stack>
#include <vector>

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

/* 找值为 x 的所有祖先节点：回溯实现 */
bool get_path_01(TreeNode *root, int x, vector<int> &res) {
  if (!root) {
    return false;
  }

  // 先将当前节点添加都 path 中
  res.push_back(root->val);
  // 找到目标节点，返回true
  if (root->val == x) {
    return true;
  }

  // 先递归左子树
  if (get_path_01(root->left, x, res)) {
    return true;
  }

  // 再递归右子树
  if (get_path_01(root->right, x, res)) {
    return true;
  }

  // 如果左右子树都没找到，说明当前节点不在路径上，进行回溯，弹出节点
  res.pop_back();

  return false;
}

/* 找值为 x 的所有祖先节点：迭代实现 */
bool get_path_02(TreeNode *root, int x, vector<int> &res) {
  stack<TreeNode *> stack_node;
  stack<vector<int>> stack_path;
  stack_node.push(root);
  stack_path.push({root->val});

  while (!stack_node.empty()) {
    TreeNode *node = stack_node.top();
    vector<int> path = stack_path.top();
    stack_node.pop();
    stack_path.pop();

    if (node->val == x) {
      res = path;
      return true;
    }

    // 这里先把左子树压入栈也是可以的，因为是依次记录路径的
    // 记录右子树的路径
    if (node->right) {
      stack_node.push(node->right);
      vector<int> right_path = path;
      right_path.push_back(node->right->val);
      stack_path.push(right_path);
    }

    // 记录左子树路径
    if (node->left) {
      stack_node.push(node->left);
      vector<int> left_path = path;
      left_path.push_back(node->left->val);
      stack_path.push(left_path);
    }
  }

  return false;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  vector<int> res;
  get_path_01(root, 4, res);

  cout << "递归实现：";
  for (int val : res) {
    cout << val << " ";
  }
  cout << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  vector<int> res;
  get_path_02(root, 4, res);

  cout << "迭代实现：";
  for (int val : res) {
    cout << val << " ";
  }
  cout << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}