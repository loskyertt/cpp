#include "recursion.hpp"

/* 寻找家谱代数：递归实现 */
int find_max_depth(TreeNode *root, int depth) {
  if (root == nullptr) {
    return depth - 1;
  }

  // 计算子树深度（子节点深度 +1），兄弟节点不增加深度
  int child_depth = find_max_depth(root->firstchild, depth + 1);
  int sibling_depth = find_max_depth(root->nextsibling, depth);

  return max(child_depth, sibling_depth);
}

/* 输出最后一代人数和成员：递归实现 */
void find_last_generation(vector<int> &last_generation, TreeNode *root, int max_depth, int current_depth) {
  if (root == nullptr) {
    return;
  }

  // 当没有孩子时，为最后一代
  if (root->firstchild == nullptr && current_depth == max_depth) {
    last_generation.push_back(root->data);
  }

  find_last_generation(last_generation, root->firstchild, max_depth, current_depth + 1);
  find_last_generation(last_generation, root->nextsibling, max_depth, current_depth);
}