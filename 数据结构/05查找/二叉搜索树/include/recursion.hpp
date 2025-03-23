#pragma once

#include "tree_node.hpp"

/* 查找操作：递归实现 */
bool find_val_recursion(TreeNode *root, int target);

/* 插入节点：递归实现 */
TreeNode *insert_recursion(TreeNode *root, int target);

/* 递归操作实现 */
TreeNode *remove_recursion(TreeNode *root, int target);