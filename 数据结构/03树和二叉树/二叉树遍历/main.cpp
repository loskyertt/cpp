#include "traverse.hpp"
#include "tree_node.hpp"
#include <iostream>

using std::cout;
using std::endl;

// 测试 bfs 遍历
void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  cout << "bfs: ";
  level_order(root);

  free_tree_node(root);
}

// 测试 dfs 遍历
void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  cout << "dfs: " << endl;
  cout << "前序遍历：";
  pre_order(root);

  cout << endl;

  cout << "中序遍历：";
  in_order(root);

  cout << endl;

  cout << "后序遍历：";
  post_order(root);
  cout << endl;

  free_tree_node(root);
}

// 测试 dfs 遍历：非递归实现
void test_03() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->left->right->left = new TreeNode(6);
  root->right->left = new TreeNode(7);

  cout << "dfs（非递归实现）: " << endl;
  cout << "前序遍历：";
  pre_order_iter(root);

  cout << "中序遍历：";
  in_order_iter(root);

  cout << "后序遍历（方式一）：";
  post_order_iter_01(root);

  cout << "后序遍历（方式二）：";
  post_order_iter_02(root);

  free_tree_node(root);
}

// 求二叉树的深度
void test_04() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  cout << "二叉树深度：" << max_depth(n1) << endl;

  free_tree_node(n1);
}

// 求二叉树叶子节点个数
void test_05() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  cout << "叶子节点个数为：" << leaf_count(n1) << endl;

  free_tree_node(n1);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  // cout << endl;
  // test_04();
  // cout << endl;
  // test_05();

  return 0;
}