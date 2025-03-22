#include <iostream>
#include <queue>
#include <stack>
#include <utility>

using namespace std;

struct TreeNode {
  int data;
  int hd; // 后代节点总数
  int hx; // 右侧兄弟节点总数
  TreeNode *first_child, *next_sibling;
  TreeNode(int x) : data(x), hd(0), hx(0), first_child(nullptr), next_sibling(nullptr) {}
};

/* 统计后代节点数（hd）：递归实现 */
int calculate_hd_recursion(TreeNode *root) {
  if (!root) {
    return 0;
  }

  int count = 0;
  TreeNode *child = root->first_child;
  while (child) {
    count += 1 + calculate_hd_recursion(child); // 子节点自身 + 其后代数量
    child = child->next_sibling;
  }

  root->hd = count;

  return count;
}

/* 统计后代节点数（hd）：迭代实现 */
void calculate_hd_iterative(TreeNode *root) {
  if (!root) {
    return;
  }

  stack<pair<TreeNode *, bool>> stk; // pair<节点指针, 是否已处理子节点>
  stk.push({root, false});

  while (!stk.empty()) {
    auto [node, precessed] = stk.top();
    stk.pop();

    // 第一次访问：将节点标记为已处理，并压入所有子节点
    if (!precessed) {
      stk.push({node, true});
      TreeNode *child = node->first_child;
      while (child) {
        stk.push({child, false});
        child = child->next_sibling;
      }
    }
    // 第二次访问（子节点已处理完毕）：计算hd
    else {
      int total = 0;
      TreeNode *child = node->first_child;
      while (child) {
        total += 1 + child->hd; // 子节点自身 + 子节点的后代
        child = child->next_sibling;
      }
      node->hd = total;
    }
  }
}

/* 统计当前节点右侧兄弟节点数（hx） */
void calculate_hx(TreeNode *root) {
  int count = 0;
  TreeNode *sibling = root->next_sibling;
  while (sibling) {
    sibling = sibling->next_sibling;
    count += 1;
  }

  root->hx = count;
}

/* 遍历所有节点，记录 hx */
void record_hx(TreeNode *root) {
  if (!root) {
    return;
  }

  queue<TreeNode *> q;
  q.push(root);

  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();

    calculate_hx(node);

    if (node->first_child != nullptr) {
      q.push(node->first_child);
    }
    if (node->next_sibling != nullptr) {
      q.push(node->next_sibling);
    }
  }
}

/* BFS遍历验证结果 */
void bfs(TreeNode *root) {
  queue<TreeNode *> q;
  q.push(root);
  while (!q.empty()) {
    TreeNode *node = q.front();
    q.pop();
    cout << node->data << " --> hd: " << node->hd << ", hx: " << node->hx << endl;
    if (node->first_child)
      q.push(node->first_child);
    if (node->next_sibling)
      q.push(node->next_sibling);
  }
}

void test_01() {
  TreeNode *root = new TreeNode(1);
  root->first_child = new TreeNode(2);
  root->first_child->first_child = new TreeNode(3);
  root->first_child->next_sibling = new TreeNode(4);
  root->first_child->first_child->next_sibling = new TreeNode(5);
  root->first_child->next_sibling->next_sibling = new TreeNode(6);
  root->first_child->next_sibling->first_child = new TreeNode(7);

  cout << "递归实现：" << endl;
  calculate_hd_recursion(root); // 计算hd
  record_hx(root);              // 计算hx
  bfs(root);
}

void test_02() {
  TreeNode *root = new TreeNode(1);
  root->first_child = new TreeNode(2);
  root->first_child->first_child = new TreeNode(3);
  root->first_child->next_sibling = new TreeNode(4);
  root->first_child->first_child->next_sibling = new TreeNode(5);
  root->first_child->next_sibling->next_sibling = new TreeNode(6);
  root->first_child->next_sibling->first_child = new TreeNode(7);

  cout << "迭代实现：" << endl;
  calculate_hd_iterative(root); // 计算hd
  record_hx(root);              // 计算hx
  bfs(root);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}
