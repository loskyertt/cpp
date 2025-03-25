#include <iostream>

using namespace std;

struct TreeNode {
  char data;
  TreeNode *left, *right;
  TreeNode(char x) : data(x), left(nullptr), right(nullptr) {}
};

/* 中序遍历 */
void in_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  // 仅在运算符节点（非叶子节点）时添加括号，而叶子节点（操作数）不加括号
  bool isOperator = (root->left != nullptr || root->right != nullptr);

  if (isOperator) {
    cout << "(";
  }
  in_order(root->left);
  cout << root->data << " ";
  in_order(root->right);

  if (isOperator) {
    cout << ")";
  }
}

void test() {
  TreeNode *root = new TreeNode('*');
  root->left = new TreeNode('+');
  root->right = new TreeNode('*');
  root->left->left = new TreeNode('a');
  root->left->right = new TreeNode('b');
  root->right->left = new TreeNode('c');
  root->right->right = new TreeNode('-');
  root->right->right->right = new TreeNode('d');

  in_order(root);
}

int main() {
  test();

  return 0;
}