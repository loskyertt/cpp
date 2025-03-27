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

/* 计算二叉树中所有双分支节点个数：迭代实现 */
int get_count_01(TreeNode *root) {
  if (!root) {
    return 0;
  }

  queue<TreeNode *> q;
  q.push(root);

  int count = 0;
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (node->left && node->right) {
      count++;
    }

    if (node->left) {
      q.push(node->left);
    }
    if (node->right) {
      q.push(node->right);
    }
  }

  return count;
}

/* 计算二叉树中所有双分支节点个数：递归实现 */
int get_count_02(TreeNode *root) {
  if (!root) {
    return 0;
  }

  int count = 0;
  if (root->left && root->right) {
    count = 1 + get_count_02(root->left) + get_count_02(root->right);
  } else {
    count = get_count_02(root->left) + get_count_02(root->right);
  }

  return count;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  int count = get_count_01(root);
  cout << "度为 2 的节点数为：" << count << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);

  int count = get_count_02(root);
  cout << "度为 2 的节点数为：" << count << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}