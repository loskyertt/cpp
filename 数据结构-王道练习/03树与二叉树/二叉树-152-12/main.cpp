#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 释放树的节点 */
// 先序遍历和中序遍历释放是不正确的！
void free_tree_node(TreeNode *root) {
  if (!root) {
    return;
  }

  free_tree_node(root->left);
  free_tree_node(root->right);

  delete root;
}

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (int num : nums) {
    cout << num << " ";
  }

  cout << endl;
}

/* 由满二叉树先序遍历，求后序遍历 */
void pre_to_post(vector<int> &pre_nums, int start, int end, vector<int> &post_nums) {
  int root = pre_nums[start]; // 暂存根，子树遍历完最后存储

  // 1|(2|45)|(3|67)
  if (start + 1 <= end) {
    start = start + 1; // 左端+1（把根节点独立出来）

    int mid = start + (end - start) / 2;
    // 此时左子树从 start+1 开始，到 mid 结束
    pre_to_post(pre_nums, start, mid, post_nums);
    // 此时右子树从 mid+1 开始，到 end 结束
    pre_to_post(pre_nums, mid + 1, end, post_nums);
  }

  post_nums.push_back(root);
}

void test_01() {
  vector<int> pre_nums = {1, 2, 4, 5, 3, 6, 7};

  cout << "先序序列：";
  print_vector(pre_nums);

  vector<int> post_nums;
  pre_to_post(pre_nums, 0, pre_nums.size() - 1, post_nums);
  cout << "后序序列：";
  print_vector(post_nums);
}

int main() {
  test_01();

  return 0;
}