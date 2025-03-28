#pragma once

#include "tree_node.hpp"
#include <vector>

using std::vector;

/* 层序遍历 */
void level_order(TreeNode *root);

/* 前序遍历 */
void pre_order(TreeNode *root);

/* 中序遍历 */
void in_order(TreeNode *root);

/* 后序遍历 */
void post_order(TreeNode *root);

/* ----------------------------------- */

/* 前序遍历：非递归实现 */
void pre_order_iter(TreeNode *root);

/* 中序遍历：非递归实现 */
void in_order_iter(TreeNode *root);

/* 后序遍历：非递归实现，方式一 */
void post_order_iter_01(TreeNode *root);

/* 后序遍历：非递归实现，方式二 */
void post_order_iter_02(TreeNode *root);