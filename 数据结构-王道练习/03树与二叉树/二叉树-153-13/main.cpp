#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 打印链表 */
void print_linked_list(TreeNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->val << " -> ";
    head = head->right;
  }
  cout << "nullptr" << endl;
}

/* 辅助函数：连接两个链表 */
TreeNode *connect_lists(TreeNode *list1, TreeNode *list2) {
  // 如果第一个链表为空，直接返回第二个链表
  if (!list1)
    return list2;
  // 如果第二个链表为空，直接返回第一个链表
  if (!list2)
    return list1;

  // 找到第一个链表的末尾
  TreeNode *tail = list1;
  while (tail->right) {
    tail = tail->right;
  }

  // 连接两个链表
  tail->right = list2;
  return list1;
}

/* 递归连接叶子节点 */
TreeNode *connect_leaf_nodes(TreeNode *root) {
  // 空树返回空
  if (!root)
    return nullptr;

  // 叶子节点，返回自身
  if (!root->left && !root->right)
    return root;

  // 递归处理左右子树
  TreeNode *left_list = connect_leaf_nodes(root->left);
  TreeNode *right_list = connect_leaf_nodes(root->right);

  // 连接左右子树的叶子节点链表
  return connect_lists(left_list, right_list);
}

void test_leaf_nodes_to_list() {
  // 构建测试二叉树
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(8);

  // 连接叶子节点
  TreeNode *leaf_list = connect_leaf_nodes(root);

  // 打印链表
  print_linked_list(leaf_list);
}

int main() {
  test_leaf_nodes_to_list();
  return 0;
}