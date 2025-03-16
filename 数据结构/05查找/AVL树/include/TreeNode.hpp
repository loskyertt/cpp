#pragma once

/* 构造二叉树，需要记录当前节点的最大高度 */
struct TreeNode {
  int val{};
  int height = 0;
  TreeNode *left{};
  TreeNode *right{};
  TreeNode() = default;
  explicit TreeNode(int x) : val(x) {}
};

/* 获取当前节点高度 */
int get_height(TreeNode *node);

/* 更新节点高度 */
void update_height(TreeNode *node);

/* 计算平衡因子 */
int get_balanced_facotor(TreeNode *node);

/* LL：右旋-旋转最右边的 */
TreeNode *rotate_right(TreeNode *node);

/* RR：左旋-旋转最左边的 */
TreeNode *rotate_left(TreeNode *node);

/* 旋转 */
TreeNode *rotate(TreeNode *node);

/* 中序遍历 */
void in_order(TreeNode *root);