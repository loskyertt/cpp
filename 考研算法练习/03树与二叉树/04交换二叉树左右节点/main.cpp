#include "swap_arr_TreeNode.hpp"
#include "swap_linked_TreeNode.hpp"
#include <climits>
#include <iostream>

void test_01() {
  vector<int> tree = {1, 2, 3, INT_MAX, 5, 6, 7};

  cout << "初始二叉树：";
  print_TreeNode(tree);

  swap_left_and_right(tree);

  cout << "交换顺序后的二叉树（数组存储，递归实现）：";
  print_TreeNode(tree);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "初始二叉树：";
  bfs(root);

  swap_left_and_right(root);
  cout << "交换顺序后的二叉树（bfs 遍历结果，链表存储，递归实现）：";
  bfs(root);

  cout << "交换顺序后的二叉树（前序遍历结果，链表存储，递归实现）：";
  pre_order(root);

  cout << endl;
}

void test_03() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  cout << "初始二叉树：";
  bfs(root);

  swap_left_and_right_iteration(root);
  cout << "交换顺序后的二叉树（bfs 遍历结果，链表存储，迭代实现）：";
  bfs(root);

  cout << "交换顺序后的二叉树（前序遍历结果，链表存储，迭代实现）：";
  pre_order(root);

  cout << endl;
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}