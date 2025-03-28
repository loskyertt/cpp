#include "traverse.hpp"
#include "tree_node.hpp"
#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using std::cout;
using std::endl;
using std::pair;
using std::queue;
using std::stack;

/* 层序遍历 */
void level_order(TreeNode *root) {
  queue<TreeNode *> queue;
  queue.push(root);

  while (!queue.empty()) {
    TreeNode *node = queue.front();
    queue.pop();

    cout << node->val << " ";

    if (node->left != nullptr) {
      queue.push(node->left);
    }
    if (node->right != nullptr) {
      queue.push(node->right);
    }
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

/* ----------------------------------- */

/* 前序遍历：非递归实现 */
void pre_order_iter(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> s;
  s.push(root);

  while (!s.empty()) {
    TreeNode *node = s.top();
    s.pop();

    cout << node->val << " ";

    // 根 -> 左 -> 右
    // 先放右子树，再放左子树（因为栈是后进先出，保证左子树先处理）
    if (node->right) {
      s.push(node->right);
    }
    if (node->left) {
      s.push(node->left);
    }
  }

  cout << endl;
}

/* 中序遍历：非递归实现 */
void in_order_iter(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> s;

  TreeNode *node = root;
  // 左 -> 根 -> 右
  while (node || !s.empty()) {
    // 先把所有左子节点入栈
    while (node) {
      s.push(node);
      node = node->left;
    }

    node = s.top();
    s.pop();

    cout << node->val << " ";

    // 再往右找
    node = node->right;
  }

  cout << endl;
}

/* 后序遍历：非递归实现，方式一 */
void post_order_iter_01(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<TreeNode *> s1, s2;
  s1.push(root);

  while (!s1.empty()) {
    TreeNode *node = s1.top();
    s1.pop();
    s2.push(node); // 逆序存入 s2（根 → 右 → 左）

    // 先把左子树压入 s1，因为一会儿要把左子树先从 s1 弹出，然后压入 s2
    if (node->left) {
      s1.push(node->left);
    }
    if (node->right) {
      s1.push(node->right);
    }
  }

  // 现在 s2 栈中存储的是 (根 → 右 → 左) 的逆序，即 (左 → 右 → 根)
  while (!s2.empty()) {
    TreeNode *node = s2.top();
    s2.pop();

    cout << node->val << " ";
  }

  cout << endl;
}

/* 后序遍历：非递归实现，方式二 */
void post_order_iter_02(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<pair<TreeNode *, bool>> s;
  s.push({root, false});
  while (!s.empty()) {
    auto [node, visited] = s.top();
    s.pop();

    // 如果没有处理过，把当前节点标记为处理过并重新压入栈，然后先压右子树，再压左子树
    if (!visited) {
      s.push({node, true});
      if (node->right) {
        s.push({node->right, false});
      }
      if (node->left) {
        s.push({node->left, false});
      }
    }
    // 处理过就可以直接输出
    else {
      cout << node->val << " ";
    }
  }

  cout << endl;
}