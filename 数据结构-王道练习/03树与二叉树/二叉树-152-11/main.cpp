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

/* 获取二叉树的最大宽度：方式一 */
int get_max_width_01(TreeNode *root) {
  if (!root) {
    return 0;
  }

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  int max_width = 0, width = 0, curr_height = 1;
  while (!q.empty()) {
    auto [node, height] = q.front();
    q.pop();

    if (height == curr_height) {
      width += 1;
    } else {
      curr_height = height;
      max_width = max(max_width, width);
      width = 1;
    }

    if (node->left) {
      q.push({node->left, height + 1});
    }
    if (node->right) {
      q.push({node->right, height + 1});
    }
  }

  return max_width;
}

/* 获取二叉树的最大宽度：方式二，优化过的 */
int get_max_width_02(TreeNode *root) {
  if (!root) {
    return 0;
  }

  queue<TreeNode *> q;
  q.push(root);

  int max_width = 0;
  while (!q.empty()) {
    // 计算当前层的宽度（即队列中已有的节点个数）
    int level_width = q.size();
    max_width = max(max_width, level_width);
    // 将当前层的节点全部弹出，然后把下一层的所有节点送进队列
    for (int i = 0; i < level_width; i++) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left) {
        q.push(node->left);
      }
      if (node->right) {
        q.push(node->right);
      }
    }
  }

  return max_width;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(8);

  int max_width = get_max_width_01(root);

  cout << "二叉树最大宽度：" << max_width << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(8);

  int max_width = get_max_width_02(root);

  cout << "二叉树最大宽度（优化过后的）：" << max_width << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}