#include <algorithm>
#include <climits>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <queue>

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

/* 判断二叉搜索树是否是 AVL 树：递归实现 */
bool is_AVL_01(TreeNode *root) {
  if (!root) {
    return true;
  }

  // lambda 辅助函数：求二叉树当前节点高度
  function<int(TreeNode *)> get_height = [&](TreeNode *node) {
    if (!node) {
      return 0;
    }

    return max(get_height(node->left), get_height(node->right)) + 1;
  };

  if (abs(get_height(root->left) - get_height(root->right)) > 1) {
    return false;
  }

  return is_AVL_01(root->left) && is_AVL_01(root->right);
}

/* 判断二叉搜索树是否是 AVL 树：迭代实现 */
bool is_AVL_02(TreeNode *root) {
  if (!root) {
    return true;
  }

  function<int(TreeNode *)> get_height = [&](TreeNode *node) {
    if (!node) {
      return 0;
    }

    return max(get_height(node->left), get_height(node->right)) + 1;
  };

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    if (abs(get_height(node->left) - get_height(node->right)) > 1) {
      return false;
    }
    if (node->left) {
      q.push(node->left);
    }
    if (node->right) {
      q.push(node->right);
    }
  }

  return true;
}

/* 上面两个实现方式的时间复杂度太高，不推荐，这是优化版的 */
bool is_AVL_improved(TreeNode *root) {
  // 返回高度，-1表示不平衡
  function<int(TreeNode *)> check_height = [&](TreeNode *node) -> int {
    if (!node)
      return 0;

    int left_height = check_height(node->left);
    if (left_height == -1)
      return -1; // 左子树不平衡

    int right_height = check_height(node->right);
    if (right_height == -1)
      return -1; // 右子树不平衡

    if (abs(left_height - right_height) > 1)
      return -1; // 当前节点不平衡

    return max(left_height, right_height) + 1; // 返回当前高度
  };

  return check_height(root) != -1;
}

void test_01() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  // root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  cout << "递归实现：" << endl;
  if (is_AVL_01(root)) {
    cout << "是 AVL 树！";
  } else {
    cout << "不是！" << endl;
  }

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  // root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  cout << "迭代实现：" << endl;
  if (is_AVL_02(root)) {
    cout << "是 AVL 树！";
  } else {
    cout << "不是！" << endl;
  }

  free_tree_node(root);
}

void test_03() {
  TreeNode *root = new TreeNode(10);
  root->left = new TreeNode(7);
  root->right = new TreeNode(15);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(9);
  root->right->left = new TreeNode(13);
  // root->right->right = new TreeNode(20);
  root->right->left->left = new TreeNode(12);
  root->right->left->right = new TreeNode(14);

  cout << "优化过的实现：" << endl;
  if (is_AVL_improved(root)) {
    cout << "是 AVL 树！";
  } else {
    cout << "不是！" << endl;
  }

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