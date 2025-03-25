#include "iteration.hpp"
#include "recursion.hpp"
#include "tree_node.hpp"
#include <iostream>

using namespace std;

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->firstchild = new TreeNode(2);
  root->firstchild->firstchild = new TreeNode(3);
  root->firstchild->nextsibling = new TreeNode(4);
  root->firstchild->firstchild->nextsibling = new TreeNode(5);
  root->firstchild->nextsibling->nextsibling = new TreeNode(6);
  root->firstchild->nextsibling->firstchild = new TreeNode(7);
  root->firstchild->nextsibling->firstchild->firstchild = new TreeNode(8);

  // 递归方式实现
  cout << "递归方式实现：" << endl;
  int max_depth = find_max_depth(root, 1);
  cout << "该家谱有 " << max_depth << " 代" << endl;

  vector<int> last_generation;
  find_last_generation(last_generation, root, max_depth, 1);
  print_arr(last_generation);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->firstchild = new TreeNode(2);
  root->firstchild->firstchild = new TreeNode(3);
  root->firstchild->nextsibling = new TreeNode(4);
  root->firstchild->firstchild->nextsibling = new TreeNode(5);
  root->firstchild->nextsibling->nextsibling = new TreeNode(6);
  root->firstchild->nextsibling->firstchild = new TreeNode(7);
  root->firstchild->nextsibling->firstchild->firstchild = new TreeNode(8);

  // 迭代方式实现
  cout << "迭代方式实现：" << endl;
  int max_depth = find_max_depth(root);
  cout << "该家谱有 " << max_depth << " 代" << endl;

  vector<int> last_generation;
  find_last_generation(last_generation, root, max_depth);
  print_arr(last_generation);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}