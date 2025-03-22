#include <climits>
#include <iostream>
#include <queue>
#include <stack>
#include <tuple>
#include <vector>

using namespace std;

struct NodeInfo {
  int index;
  int min_val;
  int max_val;
};

// 关键点：BST 的定义要求左子树的所有节点都小于根节点，右子树的所有节点都大于根节点。不能只检查当前节点的直接子节点，而没有验证整个子树。示例：{10, 5, 15, 3, 8, 13, 20}

/* 判断是否为 BST ：迭代方式，stack 实现 */
bool iteration_stack(vector<int> &tree) {
  if (tree.empty()) {
    return true;
  }

  stack<NodeInfo> nodeStack;
  nodeStack.push({0, INT_MIN, INT_MAX});

  while (!nodeStack.empty()) {
    NodeInfo current = nodeStack.top();
    nodeStack.pop();

    int index = current.index;
    int min_val = current.min_val;
    int max_val = current.max_val;

    // 跳过空节点
    if (index >= tree.size() || tree[index] == -1) {
      continue;
    }

    int current_val = tree[index];
    if (current_val <= min_val || current_val >= max_val) {
      return false;
    }

    // 左子节点入栈：范围 (min_val, current_val)
    nodeStack.push({2 * index + 1, min_val, current_val});
    // 右子节点入栈：范围 (current_val, max_val)
    nodeStack.push({2 * index + 2, current_val, max_val});
  }

  return true;
}

/* 判断是否为 BST ：迭代方式，queue 实现 */
bool iteration_queue(vector<int> &tree) {
  if (tree.empty()) {
    return true;
  }

  int n = tree.size();

  queue<tuple<int, int, int>> q;
  q.push({0, INT_MIN, INT_MAX});

  while (!q.empty()) {
    auto [index, min_val, max_val] = q.front();
    q.pop();

    if (tree[index] <= min_val || tree[index] >= max_val) {
      return false;
    }

    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < tree.size() && tree[left] != -1) {
      q.push({left, min_val, tree[index]});
    }
    if (right < tree.size() && tree[right] != -1) {
      q.push({right, tree[index], max_val});
    }
  }

  return true;
}

/* 判断是否为 BST ：递归方式*/
bool recursion(const vector<int> &tree, int index, int min_val, int max_val) {
  // 检查当前节点是否为空（索引越界或值为-1均表示节点不存在）
  if (index >= tree.size() || tree[index] == -1) {
    return true; // BST的规则是：所有存在的节点必须满足 左子树 < 根节点 < 右子树。空节点（不存在的节点）不会违反这一规则，因此它们被视为合法的“占位符”。
  }

  int current_val = tree[index];
  // 检查当前节点值是否在允许范围内
  if (current_val <= min_val || current_val >= max_val) {
    return false;
  }

  // 递归检查左子树（左子节点值必须 < current_val）和右子树（右子节点值必须 > current_val）
  return recursion(tree, 2 * index + 1, min_val, current_val) &&
         recursion(tree, 2 * index + 2, current_val, max_val);
}

bool isBST_recursion(const vector<int> &tree) {
  if (tree.empty())
    return true; // 空树视为BST
  return recursion(tree, 0, INT_MIN, INT_MAX);
}

void test_01() {
  vector<int> tree = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27}; // 满足 BST 条件
  cout << "递归实现：" << endl;
  if (isBST_recursion(tree)) {
    cout << "是二叉搜索树" << endl;
  } else {
    cout << "不是！" << endl;
  }
}

void test_02() {
  vector<int> tree = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27}; // 满足 BST 条件
  cout << "迭代实现（stack）：" << endl;
  if (iteration_stack(tree)) {
    cout << "是二叉搜索树！" << endl;
  } else {
    cout << "不是！" << endl;
  }
}

void test_03() {
  vector<int> tree = {40, 25, 60, -1, 30, -1, 80, -1, -1, 27}; // 满足 BST 条件
  cout << "迭代实现（queue）：" << endl;
  if (iteration_queue(tree)) {
    cout << "是二叉搜索树！" << endl;
  } else {
    cout << "不是！" << endl;
  }
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}