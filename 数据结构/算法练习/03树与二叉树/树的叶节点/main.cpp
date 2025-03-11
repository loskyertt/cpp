#include <iostream>
#include <queue>
#include <utility>

using namespace std;

struct TreeNode {
  int data;
  TreeNode *firstchild, *nextsibling;
  TreeNode(int x) : data(x), firstchild(nullptr), nextsibling(nullptr) {}
};

/* 获取叶节点信息和层数：递归实现 */
void get_node_depth_recursion(TreeNode *root, int depth = 1) {
  if (root == nullptr) {
    return;
  }

  if (root->firstchild == nullptr) {
    cout << "叶节点：" << root->data << " " << "层数：" << depth << endl;
  }

  get_node_depth_recursion(root->firstchild, depth + 1);
  // nextsibling 本身是同层的节点，深度不应该增加！
  get_node_depth_recursion(root->nextsibling, depth);
}

/* 获取叶节点信息和层数：迭代实现 */
void get_node_depth_iteration(TreeNode *root) {
  if (!root) {
    return;
  }

  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();

    if (node->firstchild == nullptr) {
      cout << "叶节点：" << node->data << " " << "层数：" << depth << endl;
    }
    if (node->firstchild != nullptr) {
      q.push({node->firstchild, depth + 1});
    }
    if (node->nextsibling != nullptr) {
      // nextsibling 本身是同层的节点，深度不应该增加！
      q.push({node->nextsibling, depth});
    }
  }
}

void test() {
  TreeNode *root = new TreeNode(1);
  root->firstchild = new TreeNode(2);
  root->firstchild->firstchild = new TreeNode(3);
  root->firstchild->nextsibling = new TreeNode(4);
  root->firstchild->firstchild->nextsibling = new TreeNode(5);
  root->firstchild->nextsibling->nextsibling = new TreeNode(6);
  root->firstchild->nextsibling->nextsibling->nextsibling = new TreeNode(10);

  cout << "递归实现：" << endl;
  get_node_depth_recursion(root);

  cout << endl;

  cout << "迭代实现：" << endl;
  get_node_depth_iteration(root);
}

int main() {
  test();

  return 0;
}