#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 获得 i 和 j 两个节点的最近的公共祖先节点 */
// 画一下图就能很好理解
int get_nearest_grandparent(vector<int> &tree, int i, int j) {
  while (i != j) {
    if (i > j) {
      i = (i - 1) / 2;
    } else {
      j = (j - 1) / 2;
    }
  }

  return i;
}

void test() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, INT_MAX, 8, 9};
  int index = get_nearest_grandparent(nums, 4, 7);

  cout << "最近公共祖先节点索引为：" << index << endl;
}

int main() {
  test();

  return 0;
}