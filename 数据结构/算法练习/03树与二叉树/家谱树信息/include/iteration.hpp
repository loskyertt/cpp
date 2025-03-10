#pragma once

#include "tree_node.hpp"

/* 寻找家谱代数：迭代实现 */
int find_max_depth(TreeNode *root);

/* 输出最后一代人数和成员：迭代实现 */
void find_last_generation(vector<int> &last_generation, TreeNode *root, int max_depth);