#include <iostream>

using namespace std;

struct TreeNode {
  char letter;
  int weight;
  TreeNode *left, *right;
  TreeNode(char x, int var = 0) : letter(x), weight(var), left(nullptr), right(nullptr) {}
};

/* 求二叉树的 WPL */
int get_WPL(TreeNode *root, int depth = 0) {
  // 遍历到叶子节点时的判断条件
  if (root->left == nullptr && root->right == nullptr) {
    return root->weight * depth;
  }

  return get_WPL(root->left, depth + 1) + get_WPL(root->right, depth + 1);
}

void test() {
  TreeNode *root = new TreeNode('a');
  root->left = new TreeNode('b');
  root->right = new TreeNode('c', 3);
  root->left->left = new TreeNode('d', 2);
  root->left->right = new TreeNode('e', 5);

  cout << "WPL = " << get_WPL(root) << endl;
}

int main() {
  test();

  return 0;
}
