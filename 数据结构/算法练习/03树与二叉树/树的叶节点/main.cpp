#include <iostream>

using namespace std;

struct TreeNode {
  int data;
  TreeNode *firstchild, *nextsibling;
  TreeNode(int x) : data(x), firstchild(nullptr), nextsibling(nullptr) {}
};

void get_node_depth(TreeNode *root, int depth = 1) {
  if (root == nullptr) {
    return;
  }

  if (root->firstchild == nullptr) {
    cout << "叶节点：" << root->data << " " << "层数：" << depth << endl;
  }

  get_node_depth(root->firstchild, depth + 1);
  // nextsibling 本身是同层的节点，深度不应该增加！
  get_node_depth(root->nextsibling, depth);
}

void test() {
  TreeNode *root = new TreeNode(1);
  root->firstchild = new TreeNode(2);
  root->firstchild->firstchild = new TreeNode(3);
  root->firstchild->nextsibling = new TreeNode(4);
  root->firstchild->firstchild->nextsibling = new TreeNode(5);
  root->firstchild->nextsibling->nextsibling = new TreeNode(6);
  root->firstchild->nextsibling->nextsibling->nextsibling = new TreeNode(10);

  get_node_depth(root);
}

int main() {
  test();

  return 0;
}