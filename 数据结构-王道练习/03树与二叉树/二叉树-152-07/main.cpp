#include <climits>
#include <iostream>
#include <stack>
#include <stdexcept>
#include <vector>

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

/* 求先序遍历第 k 个节点的值：借助额外数组实现 */
void get_pre_order_k_01(TreeNode *root, vector<int> &nums, int k) {
  if (!root) {
    return;
  }

  nums.push_back(root->val);
  get_pre_order_k_01(root->left, nums, k);
  get_pre_order_k_01(root->right, nums, k);
}

/* 求先序遍历第 k 个节点的 */
// 注意 count 必须是引用传参，否则就需要维护一个 count 的全局变量
int get_pre_order_k_02(TreeNode *root, int k, int &count) {
  if (!root) {
    return 0;
  }

  // 先序遍历：根 -> 左 -> 右
  count++;
  if (count == k) {
    return root->val;
  }

  // 先递归左子树，如果在左子树找到了第 k 个节点，返回它的值
  int left_result = get_pre_order_k_02(root->left, k, count);
  if (left_result != 0) {
    return left_result;
  }

  // 再递归右子树
  int right_result = get_pre_order_k_02(root->right, k, count);
  if (right_result != 0) {
    return right_result;
  }

  return 0;
}

/* 求先序遍历第 k 个节点的值：栈实现 */
int get_pre_order_k_03(TreeNode *root, int k) {
  if (!root) {
    throw out_of_range("树为空！");
  }

  stack<TreeNode *> s;
  s.push(root);
  int count = 0;
  while (!s.empty()) {
    TreeNode *node = s.top();
    s.pop();
    count++;
    if (count == k) {
      return node->val;
    }

    // 注意：先序遍历是 根 -> 左 -> 右
    // 所以栈中要先放右子树，再放左子树
    if (node->right) {
      s.push(node->right);
    }
    if (node->left) {
      s.push(node->left);
    }
  }

  throw out_of_range("没有目标节点！");
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  vector<int> res;
  int k = 5;
  get_pre_order_k_01(root, res, k);

  cout << "递归（辅助数组实现）：" << endl;
  cout << "第 " << k << " 个节点的值为：" << res[k - 1] << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  int k = 5, count = 0;
  int val = get_pre_order_k_02(root, k, count);

  cout << "递归：" << endl;
  cout << "第 " << k << " 个节点的值为：" << val << endl;

  free_tree_node(root);
}

void test_03() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->right = new TreeNode(6);

  int k = 5;
  int val = get_pre_order_k_03(root, k);

  cout << "栈实现：" << endl;
  cout << "第 " << k << " 个节点的值为：" << val << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}