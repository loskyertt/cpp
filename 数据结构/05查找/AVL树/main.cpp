#include "iteration.hpp"
#include "recursion.hpp"
#include <iostream>
#include <vector>

using namespace std;

// 测试递归实现的
void test_recursion() {
  vector<int> nums = {
      2,
      4,
      1,
      5,
      7,
      10,
      11,
      14,
      8,
      6,
      3,
  };

  TreeNode *root = nullptr;
  for (int num : nums) {
    root = insert_recursion(root, num);
  }
  cout << "递归实现：" << endl;
  // 初始树
  cout << "初始树：";
  in_order(root);
  cout << endl;

  cout << "删除节点后的树：";
  root = remove_recursion(root, 10);
  in_order(root);
  cout << endl;
}

// 测试递归实现的
void test_ieration() {
  vector<int> nums = {
      2,
      4,
      1,
      5,
      7,
      10,
      11,
      14,
      8,
      6,
      3,
  };

  TreeNode *root = nullptr;
  for (int num : nums) {
    root = insert_iteration(root, num);
  }
  cout << "迭代实现：" << endl;
  // 初始树
  cout << "初始树：";
  in_order(root);
  cout << endl;

  cout << "删除节点后的树：";
  root = remove_iteration(root, 10);
  in_order(root);
  cout << endl;
}

int main() {
  test_recursion();
  test_ieration();

  return 0;
}