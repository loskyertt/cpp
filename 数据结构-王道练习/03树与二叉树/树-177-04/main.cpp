#include <climits>
#include <iostream>
#include <queue>

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

/* 求森林叶结点树：迭代实现 */
int get_leaf_num_01(TreeNode *root) {
  if (!root) {
    return 0;
  }

  queue<TreeNode *> q;
  q.push(root);
  int count = 0;

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    // 如果左孩子为空，说明就是叶子节点
    if (!node->first_child) {
      count++;
    }

    if (node->first_child) {
      q.push(node->first_child);
    }
    if (node->next_sibling) {
      q.push(node->next_sibling);
    }
  }

  return count;
}

/* 求森林叶结点数：递归实现 */
int get_leaf_num_02(TreeNode *root) {
  if (!root) {
    return 0;
  }

  int count = 0;
  TreeNode *current = root;

  // 遍历当前层的所有兄弟节点
  while (current) {
    // 如果没有孩子，是叶子节点
    if (!current->first_child) {
      count++;
    }
    // 如果有孩子，递归计算孩子树的叶子节点
    else {
      count += get_leaf_num_02(current->first_child);
    }

    // 移动到下一个兄弟节点
    current = current->next_sibling;
  }

  return count;
}

void test_01() {
  TreeNode *root = new TreeNode(0);
  root->first_child = new TreeNode(1);
  root->first_child->next_sibling = new TreeNode(4);
  root->next_sibling = new TreeNode(2);
  root->next_sibling->first_child = new TreeNode(5);
  root->next_sibling->first_child->next_sibling = new TreeNode(6);
  root->next_sibling->first_child->next_sibling->next_sibling = new TreeNode(7);
  root->next_sibling->next_sibling = new TreeNode(3);
  root->next_sibling->next_sibling->first_child = new TreeNode(8);
  root->next_sibling->next_sibling->first_child->next_sibling = new TreeNode(10);
  root->next_sibling->next_sibling->first_child->first_child = new TreeNode(9);

  int leaf_num = get_leaf_num_01(root);

  cout << "森林的叶结点数为（迭代实现）：" << leaf_num << endl;

  free_tree_node(root);
}

void test_02() {
  TreeNode *root = new TreeNode(0);
  root->first_child = new TreeNode(1);
  root->first_child->next_sibling = new TreeNode(4);
  root->next_sibling = new TreeNode(2);
  root->next_sibling->first_child = new TreeNode(5);
  root->next_sibling->first_child->next_sibling = new TreeNode(6);
  root->next_sibling->first_child->next_sibling->next_sibling = new TreeNode(7);
  root->next_sibling->next_sibling = new TreeNode(3);
  root->next_sibling->next_sibling->first_child = new TreeNode(8);
  root->next_sibling->next_sibling->first_child->next_sibling = new TreeNode(10);
  root->next_sibling->next_sibling->first_child->first_child = new TreeNode(9);

  int leaf_num = get_leaf_num_02(root);

  cout << "森林的叶结点数为（递归实现）：" << leaf_num << endl;

  free_tree_node(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}