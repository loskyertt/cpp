#include <climits>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 释放树的节点 */
// 先序遍历和中序遍历释放是不正确的！
void free_tree_node(TreeNode *root) {
  if (!root) {
    return;
  }

  free_tree_node(root->left);
  free_tree_node(root->right);

  delete root;
}

/* 求 p 和 q 节点的最近公共节点：递归实现 */
TreeNode *get_nearest_ancestor_01(TreeNode *root, int p, int q) {
  if (!root) {
    return nullptr;
  }

  // 如果根节点等于 p 或者 q，那么根节点就是 p 和 q 最近的祖先节点
  if (root->val == p || root->val == q) {
    return root;
  }

  // 递归查找左子树和右子树
  TreeNode *left = get_nearest_ancestor_01(root->left, p, q);
  TreeNode *right = get_nearest_ancestor_01(root->right, p, q);

  // 如果 p 和 q 分别在左右子树，说明根节点就是 p 和 q 的最近祖先节点
  if (left && right) {
    return root;
  }

  // 如果 p 和 q 都在左子树，返回左子树的结果，否则返回右子树的结果
  return left ? left : right;
}

/* 求 p 和 q 指向节点的最近公共节点：哈希表实现 */
TreeNode *get_nearest_ancestor_02(TreeNode *root, TreeNode *p, TreeNode *q) {
  if (!root) {
    return nullptr;
  }

  unordered_map<TreeNode *, TreeNode *> parent_map; // key: 子节点 value: 父节点
  unordered_set<TreeNode *> path;                   // 记录 p 指向节点的路径
  queue<TreeNode *> queue_nodes;                    // 用于 bfs
  queue_nodes.push(root);
  parent_map[root] = nullptr;

  // 通过 bfs 遍历完整棵树，然后记录节点的父节点信息
  // 只有在 parent_map 同时存在 p 和 q 后，才退出循环
  while (!parent_map.count(p) || !parent_map.count(q)) {
    TreeNode *node = queue_nodes.front();
    queue_nodes.pop();

    if (node->left) {
      queue_nodes.push(node->left);
      parent_map[node->left] = node; // key: 左子树 value: 父节点
    }
    if (node->right) {
      queue_nodes.push(node->right);
      parent_map[node->right] = node; // key: 右子树 value: 父节点
    }
  }

  while (p) {
    p = parent_map[p];
    path.insert(p); // 记录 p 的路径
  }

  // 找到和 q 的第一个公共祖先
  while (!path.count(q)) {
    q = parent_map[q]; // 让 q 一直往回退
  }

  return q;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(8);

  TreeNode *res = get_nearest_ancestor_01(root, 4, 7);
  cout << "res: " << res->val << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *n0 = new TreeNode(1);
  TreeNode *n1 = new TreeNode(2);
  TreeNode *n2 = new TreeNode(3);
  TreeNode *n3 = new TreeNode(4);
  TreeNode *n4 = new TreeNode(5);
  TreeNode *n5 = new TreeNode(6);
  TreeNode *n6 = new TreeNode(7);
  TreeNode *n7 = new TreeNode(8);

  n0->left = n1;
  n0->right = n2;
  n1->left = n3;
  n1->right = n4;
  n2->right = n5;
  n4->left = n6;
  n4->right = n7;

  TreeNode *res = get_nearest_ancestor_02(n0, n3, n6);
  cout << "res: " << res->val << endl;

  free_tree_node(n0);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}