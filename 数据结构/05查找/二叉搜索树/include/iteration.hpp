#pragma once

#include "tree_node.hpp"

/* 查找操作：迭代实现 */
bool find_val_iteration(TreeNode *root, int val);

/* 插入操作：迭代插入 */
void insert_iteration(TreeNode *&root, int val);

/* 删除节点：迭代实现 */
void remove_iteration(TreeNode *root, int num);