#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* 二叉树节点结构体 */
struct TreeNode {
  int val;         // 节点值
  TreeNode *left;  // 左子节点指针
  TreeNode *right; // 右子节点指针
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 层序遍历*/
vector<int> level_order(TreeNode *root) {
  queue<TreeNode *> queue;
  queue.push(root);

  vector<int> vec;
  while (!queue.empty()) {
    TreeNode *node = queue.front();
    queue.pop();
    vec.push_back(node->val); // 保存节点值
    if (node->left != nullptr) {
      queue.push(node->left);
    }
    if (node->right != nullptr) {
      queue.push(node->right);
    }
  }
  return vec;
}

void test_level_order() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  vector<int> res = level_order(n1);

  for (int val : res) {
    cout << val << " ";
  }

  cout << endl;
}

/* 前序遍历 */
void pre_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  cout << root->val << " ";
  pre_order(root->left);
  pre_order(root->right);
}

/* 中序遍历 */
void in_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}

/* 后序遍历 */
void post_order(TreeNode *root) {
  if (root == nullptr) {
    return;
  }
  post_order(root->left);
  post_order(root->right);
  cout << root->val << " ";
}

void test_dfs() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  cout << "前序遍历：";
  pre_order(n1);
  cout << endl;
  cout << "中序遍历：";
  in_order(n1);
  cout << endl;
  cout << "后序遍历：";
  post_order(n1);
  cout << endl;
}

/* 求二叉树最大深度 */
int max_depth(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }

  int left_depth = max_depth(root->left);
  int right_depth = max_depth(root->right);

  return max(left_depth, right_depth) + 1;
}

void test_max_depth() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  cout << "max depth: " << max_depth(n1) << endl;
}

/* 求二叉树叶子节点个数 */
int lead_count(TreeNode *root) {
  if (root == nullptr) {
    return 0;
  }
  if (root->left == nullptr && root->right == nullptr) {
    return 1;
  }
  return lead_count(root->left) + lead_count(root->right);
}

void test_lead_count() {
  /* 初始化二叉树 */
  // 初始化节点
  TreeNode *n1 = new TreeNode(1);
  TreeNode *n2 = new TreeNode(2);
  TreeNode *n3 = new TreeNode(3);
  TreeNode *n4 = new TreeNode(4);
  TreeNode *n5 = new TreeNode(5);
  // 构建节点之间的引用（指针）
  n1->left = n2;
  n1->right = n3;
  n2->left = n4;
  n2->right = n5;

  cout << "叶子节点个数为：" << lead_count(n1) << endl;
}

int main() {
  // test_level_order();
  test_dfs();
  // test_max_depth();
  // test_lead_count();

  return 0;
}