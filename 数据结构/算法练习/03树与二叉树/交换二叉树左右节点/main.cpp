#include "swap_arr_TreeNode.hpp"
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

int main() {
  // test_arr();

  return 0;
}