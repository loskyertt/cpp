#include "TreeNode.hpp"
#include <climits>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

// private:
void ArrayBinaryTree::dfs(vector<int> &res, string order, int index) {
  if (val(index) == INT_MAX) {
    return;
  }

  // 前序遍历
  if (order == "pre") {
    res.push_back(val(index));
  }

  dfs(res, order, left(index));

  // 中序遍历
  if (order == "in") {
    res.push_back(val(index));
  }

  dfs(res, order, right(index));

  // 后序遍历
  if (order == "post") {
    res.push_back(val(index));
  }
}

// public:
ArrayBinaryTree::ArrayBinaryTree(vector<int> arr) {
  tree = arr;
}

/* 列表容量 */
int ArrayBinaryTree::size() {
  return tree.size();
}

/* 获取索引为 i 节点的值 */
int ArrayBinaryTree::val(int i) {
  if (i < 0 || i >= size()) {
    return INT_MAX;
  }

  return tree[i];
}

/* 获取索引为 i 节点的左子节点的索引 */
int ArrayBinaryTree::left(int i) {
  return 2 * i + 1;
}

/* 获取索引为 i 节点的右子节点的索引 */
int ArrayBinaryTree::right(int i) {
  return 2 * i + 2;
}

/* 获取索引为 i 节点的父节点的索引 */
int ArrayBinaryTree::parent(int i) {
  return (i - 1) / 2;
}

/* 层序遍历 */
vector<int> ArrayBinaryTree::levelOrder() {
  vector<int> res;
  for (int val : tree) {
    if (val != -1) {
      res.push_back(val);
    }
  }

  return res;
}

/* 前序遍历 */
vector<int> ArrayBinaryTree::pre_order() {
  vector<int> res;
  dfs(res, "pre", 0);

  return res;
}

/* 中序遍历 */
vector<int> ArrayBinaryTree::in_order() {
  vector<int> res;
  dfs(res, "in", 0);

  return res;
}

/* 后序遍历 */
vector<int> ArrayBinaryTree::post_order() {
  vector<int> res;
  dfs(res, "post", 0);

  return res;
}

/* 前序遍历：迭代实现 */
vector<int> ArrayBinaryTree::pre_order_iteration() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<int> nodeStack;
  nodeStack.push(0);

  while (!nodeStack.empty()) {
    int index = nodeStack.top();
    nodeStack.pop();

    if (val(index) == INT_MAX) {
      continue;
    }
    res.push_back(val(index));

    // 先压右子节点，再压左子节点（栈是先进后出）
    if (right(index) < size()) {
      nodeStack.push(right(index));
    }
    if (left(index) < size()) {
      nodeStack.push(left(index));
    }
  }

  return res;
}

/* 中序遍历：迭代实现 */
vector<int> ArrayBinaryTree::in_order_iteration() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  stack<int> nodeStack;
  int index = 0;

  while (index < size() || !nodeStack.empty()) {
    // 先让左子树入栈
    // 若索引没有超出数组长度以及该索引对应的节点有值（非 INT_MAX）
    while (index < size() && val(index) != INT_MAX) {
      nodeStack.push(index);
      index = left(index);
    }

    index = nodeStack.top();
    nodeStack.pop();

    res.push_back(val(index));
    index = right(index);
  }

  return res;
}

/* 后序遍历：迭代实现，方式一 */
vector<int> ArrayBinaryTree::post_order_iteration_1() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  // stk1: 根 -> 右 -> 左 ；stk2: 左 -> 右 -> 根
  // 显然，stk2 是用来反转 stk1 中的节点的
  stack<int> stk1, stk2;
  stk1.push(0);

  while (!stk1.empty()) {
    int index = stk1.top();
    stk1.pop();
    stk2.push(index);

    if (left(index) < size() && val(left(index)) != INT_MAX) {
      stk1.push(left(index));
    }
    if (right(index) < size() && val(right(index)) != INT_MAX) {
      stk1.push(right(index));
    }
  }

  while (!stk2.empty()) {
    int index = stk2.top();
    stk2.pop();

    res.push_back(val(index));
  }

  return res;
}

/* 后序遍历：迭代实现，方式二 */
vector<int> ArrayBinaryTree::post_order_iteration_2() {
  if (tree.empty() || val(0) == INT_MAX) {
    throw out_of_range("ERROR!");
  }

  vector<int> res;
  // 采用标记的方式实现后续遍历
  stack<pair<int, bool>> stk;
  stk.push({0, false});

  while (!stk.empty()) {
    auto [index, visited] = stk.top();
    stk.pop();

    // 如果还没访问过，把该节点标记为访问过，并把该节点的左右子树压入栈，
    if (!visited) {
      stk.push({index, true});

      if (right(index) < size() && val(right(index)) != INT_MAX) {
        stk.push({right(index), false});
      }

      if (left(index) < size() && val(left(index)) != INT_MAX) {
        stk.push({left(index), false});
      }
    } else {
      res.push_back(val(index));
    }
  }

  return res;
}