#include "swap_arr_TreeNode.hpp"
#include <climits>
#include <iostream>
#include <utility>

/* 左子树索引 */
int left_index(int index) {
  return 2 * index + 1;
}

/* 右子树索引 */
int right_index(int index) {
  return 2 * index + 2;
}

/* 交换二叉树的所有左、右子树 */
// 实现后的效果与链式的二叉树不太一样！！
void swap_left_and_right(vector<int> &tree, int index) {
  // 索引不正确或者当前索引没有节点
  if (index >= tree.size() || tree[index] == INT_MAX) {
    return;
  }

  // 交换顺序
  swap(tree[left_index(index)], tree[right_index(index)]);

  swap_left_and_right(tree, left_index(index));
  swap_left_and_right(tree, right_index(index));
}

/* 打印二叉树 */
void print_TreeNode(vector<int> tree) {
  for (int num : tree) {
    if (num == INT_MAX) {
      cout << "nullptr" << " ";
    } else {
      cout << num << " ";
    }
  }
  cout << endl;
}