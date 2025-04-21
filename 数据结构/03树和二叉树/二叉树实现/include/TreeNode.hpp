#pragma oce

#include <string>
#include <vector>

using namespace std;

/* 数组实现二叉树 */
class ArrayBinaryTree {

private:
  vector<int> tree;

  void dfs(vector<int> &res, string order, int index);

public:
  ArrayBinaryTree(vector<int> arr);

  /* 列表容量 */
  int size();

  /* 获取索引为 i 节点的值 */
  int val(int i);

  /* 获取索引为 i 节点的左子节点的索引 */
  int left(int i);

  /* 获取索引为 i 节点的右子节点的索引 */
  int right(int i);

  /* 获取索引为 i 节点的父节点的索引 */
  int parent(int i);

  /* 层序遍历 */
  vector<int> levelOrder();

  /* 前序遍历 */
  vector<int> pre_order();

  /* 中序遍历 */
  vector<int> in_order();

  /* 后序遍历 */
  vector<int> post_order();

  /* 前序遍历：迭代实现 */
  vector<int> pre_order_iteration();

  /* 中序遍历：迭代实现 */
  vector<int> in_order_iteration();

  /* 后序遍历：迭代实现，方式一 */
  vector<int> post_order_iteration_1();

  /* 后序遍历：迭代实现，方式二 */
  vector<int> post_order_iteration_2();
};