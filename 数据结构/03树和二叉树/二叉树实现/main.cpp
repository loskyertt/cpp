#include "TreeNode.hpp"
#include <climits>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> arr) {
  for (int val : arr) {
    cout << val << " ";
  }
  cout << endl;
}

void test() {
  vector<int> arr = {40, 25, 60, INT_MAX, 30, INT_MAX, 80, INT_MAX, INT_MAX, 27};

  ArrayBinaryTree tree(arr);

  cout << "实际占用数组大小：" << tree.size() << endl;

  vector<int> pre_order_res = tree.pre_order();
  cout << "前序遍历为：";
  print_vector(pre_order_res);

  vector<int> in_order_res = tree.in_order();
  cout << "中序遍历为：";
  print_vector(in_order_res);

  vector<int> post_order = tree.post_order();
  cout << "后续遍历为：";
  print_vector(post_order);

  vector<int> pre_order_res_iteration = tree.pre_order_iteration();
  cout << "前序遍历为（迭代实现）：";
  print_vector(pre_order_res_iteration);
}

int main() {

  test();

  return 0;
}