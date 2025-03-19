#pragma once

#include <vector>

using namespace std;

struct TreeNode {
  int data;
  TreeNode *firstchild, *nextsibling;
  TreeNode(int x) : data(x), firstchild(nullptr), nextsibling(nullptr) {}
};

/* 打印数组 */
void print_arr(vector<int> nums);