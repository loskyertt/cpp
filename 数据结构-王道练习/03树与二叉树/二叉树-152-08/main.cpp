#include <climits>
#include <iostream>
#include <queue>
#include <stdexcept>

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

/* 先序遍历 */
void pre_order(TreeNode *root) {
  if (!root) {
    return;
  }

  cout << root->val << " ";
  pre_order(root->left);
  pre_order(root->right);
}

/* 删除值为 x 的节点及其子树：迭代实现 */
void delete_node_01(TreeNode *&root, int x) {
  if (!root) {
    throw out_of_range("树为空！");
  }

  // 参数传入 &root 的目的就是为了处理 root。如果加 &，就成值传参了，函数中的 root 指针指向修改不会影响到外面的
  if (root->val == x) {
    free_tree_node(root);
    root = nullptr;
    // 注意这里要及时退出！
    return;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    // 处理当前节点的左子树
    if (node->left) {
      if (node->left->val == x) {
        free_tree_node(node->left);
        node->left = nullptr;
      } else {
        q.push(node->left);
      }
    }

    // 处理当前节点的右子树
    if (node->right) {
      if (node->right->val == x) {
        free_tree_node(node->right);
        node->right = nullptr;
      } else {
        q.push(node->right);
      }
    }
  }
}

/* 删除值为 x 的节点及其子树：递归实现 */
TreeNode *delete_node_02(TreeNode *root, int x) {
  if (!root) {
    return nullptr;
  }

  if (root->val == x) {
    free_tree_node(root);
    return nullptr;
  }

  // 删除左边子树中含值 x 的节点及其子树
  root->left = delete_node_02(root->left, x);
  // 删除右边子树中含值 x 的节点及其子树
  root->right = delete_node_02(root->right, x);

  // 左边和右边的子树处理完毕后，再把 root 返回出去
  return root;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  // 这里 delete_node_01 函数中，如果不按引用传参的话，如果删除的是根节点，会导致函数外的 root 指针变成野指针，因为节点已经都释放了
  delete_node_01(root, 3);

  cout << "迭代实现：";
  pre_order(root);
  cout << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  root = delete_node_02(root, 3);

  cout << "递归实现：";
  pre_order(root);
  cout << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}