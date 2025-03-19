#include "swap_arr_TreeNode.hpp"
#include "swap_linked_TreeNode.hpp"
#include <climits>
#include <iostream>

void test_arr() {
  vector<int> tree = {1, 2, 3, INT_MAX, 5, 6, 7};

  cout << "初始二叉树：";
  print_TreeNode(tree);

  swap_left_and_right(tree);
  cout << "交换顺序后的二叉树：";
  print_TreeNode(tree);
}

void test_linking() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "初始二叉树：";
  bfs(root);

  swap_left_and_right(root);
  cout << "交换顺序后的二叉树（bfs 遍历结果）：";
  bfs(root);

  cout << "交换顺序后的二叉树（前序遍历结果）：";
  pre_order(root);
}

int main() {
  test_arr();
  test_linking();

  return 0;
}