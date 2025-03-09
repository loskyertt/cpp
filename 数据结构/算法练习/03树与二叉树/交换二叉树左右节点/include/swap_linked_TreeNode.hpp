#pragma once

/* 链式存储的交换方法 */

struct TreeNode {
  int var;
  TreeNode *left, *right;
  TreeNode(int x) : var(x), left(nullptr), right(nullptr) {}
};