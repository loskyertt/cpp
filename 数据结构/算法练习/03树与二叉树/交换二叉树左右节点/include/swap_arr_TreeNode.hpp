#pragma once

#include <vector>

using namespace std;

/* 顺序存储的交换方法 */

/* 左子树索引 */
int left_index(int index);

/* 右子树索引 */
int right_index(int index);

/* 交换r二叉树的所有左、右子树 */
void swap_left_and_right(vector<int> &tree, int index = 0);

/* 打印二叉树 */
void print_TreeNode(vector<int> tree);