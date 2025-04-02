#include <climits>
#include <cstdlib>
#include <iostream>
#include <stdexcept>

using namespace std;

struct TreeNode {
  int val;
  int count;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), count(0), left(nullptr), right(nullptr) {}
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

/* 输出 count */
void print_info(TreeNode *root) {
  if (!root) {
    return;
  }

  print_info(root->left);
  cout << "val: " << root->val << "\tcount: " << root->count << endl;
  print_info(root->right);
}

/* 更新树的 count */
void update_count(TreeNode *node) {
  if (!node)
    return;

  // 更新左右子树的 count
  update_count(node->left);
  update_count(node->right);

  node->count = 0;

  // 更新根节点的 count
  if (node->left) {
    node->count += node->left->count + 1;
  }
  if (node->right) {
    node->count += node->right->count + 1;
  }
}

/* 查找二叉排序树中第 k 小的元素 */
int find_smallest_k(TreeNode *root, int k) {
  if (!root) {
    throw runtime_error("树为空或 k 值无效");
  }

  // 获取左子树的节点总数
  int left_size = root->left ? root->left->count + 1 : 0;

  if (k <= left_size) {
    // 第k小的元素在左子树中
    return find_smallest_k(root->left, k);
  } else if (k == left_size + 1) {
    // 根节点就是第k小的元素
    return root->val;
  } else {
    // 第k小的元素在右子树中
    // 需要减去左子树的节点数和根节点
    return find_smallest_k(root->right, k - left_size - 1);
  }
}

void test_01() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  update_count(root);
  print_info(root);
  cout << endl;

  int k = 3;
  int val = find_smallest_k(root, k);
  cout << "第 " << k << " 小的节点值为：" << val << endl;

  free_tree_node(root);
}

int main() {
  test_01();

  return 0;
}