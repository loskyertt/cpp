#include "iteration.hpp"
#include "recursion.hpp"
#include <iostream>

using namespace std;

/* 中序遍历：对二叉搜索树来说，就是从小到大的遍历 */
void in_order(TreeNode *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}

void test_01() {
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(4);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);
  root->right->left = new TreeNode(10);
  // root->left->right->left = new TreeNode(5);

  cout << "初始二叉搜索树：";
  in_order(root);

  cout << endl;

  // 迭代操作实现
  cout << "迭代操作实现：" << endl;
  insert_iteration(root, 7);
  cout << "插入新节点后的二叉搜索树：";
  in_order(root);

  cout << endl;

  cout << "删除节点后的二叉树：";
  remove_iteration(root, 4);
  in_order(root);
}

void test_02() {
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(4);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);
  root->right->left = new TreeNode(10);
  // root->left->right->left = new TreeNode(5);

  // 递归操作实现
  cout << "递归操作实现：" << endl;
  insert_recursion(root, 7);
  cout << "插入新节点后的二叉搜索树：";
  in_order(root);

  cout << endl;

  cout << "删除节点后的二叉树：";
  remove_recursion(root, 4);
  in_order(root);
}

void test_03() {
  TreeNode *root = nullptr;
  insert_iteration(root, 10);

  cout << "插入一个新节点后：";
  in_order(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  // test_03();

  return 0;
}