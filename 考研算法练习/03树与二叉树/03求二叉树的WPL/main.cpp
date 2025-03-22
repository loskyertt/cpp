#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
  char letter;
  int weight;
  TreeNode *left, *right;
  TreeNode(char x, int var = 0) : letter(x), weight(var), left(nullptr), right(nullptr) {}
};

/* 求二叉树的 WPL：迭代实现 */
int get_WPL_iteration(TreeNode *root) {
  queue<pair<TreeNode *, int>> q; // <node, path>
  q.push({root, 0});

  // 总权重先设为 0
  int total_WPL = 0;

  // BFS 遍历
  while (!q.empty()) {
    auto [node, path] = q.front();
    q.pop();

    // 如果节点为叶节点，则计算权重
    if (node->left == nullptr && node->right == nullptr) {
      total_WPL += node->weight * path;
    }

    if (node->left) {
      q.push({node->left, path + 1});
    }
    if (node->right) {
      q.push({node->right, path + 1});
    }
  }

  return total_WPL;
}

/* 求二叉树的 WPL：递归实现 */
int get_WPL_recursion(TreeNode *root, int depth = 0) {
  // 遍历到叶子节点时的判断条件
  if (root->left == nullptr && root->right == nullptr) {
    return root->weight * depth;
  }

  return get_WPL_recursion(root->left, depth + 1) +
         get_WPL_recursion(root->right, depth + 1);
}

void test() {
  TreeNode *root = new TreeNode('a', 1);
  root->left = new TreeNode('b');
  root->right = new TreeNode('c', 3);
  root->left->left = new TreeNode('d', 2);
  root->left->right = new TreeNode('e', 5);

  cout << "递归实现：" << endl;
  cout << "WPL = " << get_WPL_recursion(root) << endl;

  cout << "迭代实现：" << endl;
  cout << "WPL = " << get_WPL_iteration(root) << endl;
}

int main() {
  test();

  return 0;
}
