#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *first_child, *next_sibling;
  TreeNode(int x) : val(x), first_child(nullptr), next_sibling(nullptr) {}
};

/* 释放树的节点 */
// 先序遍历和中序遍历释放是不正确的！
void free_tree_node(TreeNode *root) {
  if (!root) {
    return;
  }

  free_tree_node(root->first_child);
  free_tree_node(root->next_sibling);

  delete root;
}

/* 递归求树的深度：方式一 */
int get_tree_depth_01(TreeNode *root, int height = 0) {
  if (!root) {
    return height;
  }

  return max(get_tree_depth_01(root->first_child, height + 1),
             get_tree_depth_01(root->next_sibling, height));
}

/* 递归求树的深度：方式二 */
int get_tree_depth_02(TreeNode *root) {
  if (!root) {
    return 0;
  }

  // 初始深度为0
  int max_depth = 0;

  // 遍历当前节点的所有兄弟节点
  TreeNode *current = root;
  while (current) {
    // 递归计算当前节点的子树深度
    int child_depth = 1; // 当前节点计为1层
    if (current->first_child) {
      child_depth += get_tree_depth_02(current->first_child);
    }

    // 更新最大深度
    max_depth = max(max_depth, child_depth);

    // 移动到下一个兄弟节点
    current = current->next_sibling;
  }

  return max_depth;
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->first_child = new TreeNode(2);
  root->first_child->next_sibling = new TreeNode(3);
  root->first_child->next_sibling->next_sibling = new TreeNode(4);
  root->first_child->first_child = new TreeNode(5);
  root->first_child->first_child->next_sibling = new TreeNode(6);

  int height = get_tree_depth_01(root);

  cout << "树的高度为（方式一）：" << height << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->first_child = new TreeNode(2);
  root->first_child->next_sibling = new TreeNode(3);
  root->first_child->next_sibling->next_sibling = new TreeNode(4);
  root->first_child->first_child = new TreeNode(5);
  root->first_child->first_child->next_sibling = new TreeNode(6);

  int height = get_tree_depth_02(root);

  cout << "树的高度为（方式二）：" << height << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}