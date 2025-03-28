#include <climits>
#include <iostream>

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

/* 判断两棵二叉树释放相似 */
bool is_similar(TreeNode *root1, TreeNode *root2) {
  // 如果两课树都为空，那就是相似的
  if (!root1 && !root2) {
    return true;
  }
  // 如果一课时为空，两一棵树不为空，那就不是相似的
  else if (!root1 || !root2) {
    return false;
  } else {
    bool check_left = is_similar(root1->left, root2->left);
    bool check_right = is_similar(root1->right, root2->right);
    return check_left && check_right;
  }
}

void test_01() {
  TreeNode *root1 = new TreeNode(1);
  root1->left = new TreeNode(2);
  root1->right = new TreeNode(3);
  root1->left->left = new TreeNode(4);
  root1->left->right = new TreeNode(5);

  TreeNode *root2 = new TreeNode(1);
  root2->left = new TreeNode(2);
  root2->right = new TreeNode(3);
  root2->left->left = new TreeNode(4);
  root2->left->right = new TreeNode(5);
  root2->right->right = new TreeNode(6);

  if (is_similar(root1, root2)) {
    cout << "两棵树相似！" << endl;
  } else {
    cout << "不相似！" << endl;
  }

  free_tree_node(root1);
  free_tree_node(root2);
}

int main() {
  test_01();

  return 0;
}