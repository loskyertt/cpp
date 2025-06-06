#include "iteration.hpp"
#include "tree_node.hpp"
#include <algorithm>
#include <queue>
// #include <stack>
#include <utility>
#include <vector>

// /* 寻找家谱代数：迭代实现 */
// int find_max_depth(TreeNode *root) {
//   stack<pair<TreeNode *, int>> stk; // 栈存储 <节点指针, 当前深度>
//   stk.push({root, 1});
//   int max_depth = 1;

//   while (!stk.empty()) {
//     auto [node, depth] = stk.top();
//     stk.pop();

//     // 处理子节点（深度+1）
//     if (node->firstchild != nullptr) {
//       stk.push({node->firstchild, depth + 1});
//       max_depth = max(max_depth, depth + 1);
//     }

//     // 处理兄弟节点（深度不变）
//     if (node->nextsibling != nullptr) {
//       stk.push({node->nextsibling, depth});
//     }
//   }

//   return max_depth;
// }

// /* 输出最后一代人数和成员：迭代（BFS）实现 */
// void find_last_generation(vector<int> &last_generation, TreeNode *root, int max_depth) {
//   if (root == nullptr) {
//     return;
//   }

//   queue<pair<TreeNode *, int>> q; // 队列存储 <节点指针, 当前深度>
//   q.push({root, 1});

//   while (!q.empty()) {
//     auto [node, depth] = q.front();
//     q.pop();

//     // 当前节点是最后一层且无子节点
//     if (node->firstchild == nullptr && depth == max_depth) {
//       last_generation.push_back(node->data);
//     }

//     // 将子节点和兄弟节点入队，这种方式不会导致重复入队！因为入队的是当前节点的所有孩子节点
//     TreeNode *child = node->firstchild;
//     while (child) {
//       q.push({child, depth + 1});
//       child = child->nextsibling;
//     }
//   }
// }

/* -------------------- 仅用队列实现：BFS 思想 -------------------- */

/* 获取家谱的代数 */
int find_max_depth(TreeNode *root) {
  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  int max_depth = 1;

  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();

    max_depth = max(max_depth, depth);

    if (node->firstchild != nullptr) {
      q.push({node->firstchild, depth + 1});
    }
    if (node->nextsibling != nullptr) {
      q.push({node->nextsibling, depth});
    }
  }

  return max_depth;
}

/* 获取最后一代人数和成员名字 */
void find_last_generation(vector<int> &res, TreeNode *root, int max_depth) {
  queue<pair<TreeNode *, int>> q;
  q.push({root, 1});

  while (!q.empty()) {
    auto [node, depth] = q.front();
    q.pop();

    if (node->firstchild == nullptr && depth == max_depth) {
      res.push_back(node->data);
    }

    if (node->firstchild != nullptr) {
      q.push({node->firstchild, depth + 1});
    }
    if (node->nextsibling != nullptr) {
      q.push({node->nextsibling, depth});
    }
  }
}