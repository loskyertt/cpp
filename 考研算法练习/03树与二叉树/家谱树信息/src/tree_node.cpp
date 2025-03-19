#include "tree_node.hpp"
#include <iostream>

/* 打印数组 */
void print_arr(vector<int> nums) {
  cout << "最后一代人数：" << nums.size() << endl;
  cout << "最后一代成员：";
  for (int num : nums) {
    cout << num << " ";
  }

  cout << endl;
}