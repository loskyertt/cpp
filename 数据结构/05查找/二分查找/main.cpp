#include <iostream>
#include <vector>

using namespace std;

/* 增加哨兵位，减少比较次数 */
int sequential_search_with_sentinel(vector<int> nums, int n, int target) {
  nums[n] = target;

  int i = 0;
  while (target != nums[i]) {
    i++;
  }

  return i != n ? i : -1;
}

/* 折半查找（对有序线性表）：递归 */
int binary_search_recursion(vector<int> nums, int left, int right, int target) {
  if (left > right) {
    return -1; // 递归终止条件
  }

  int mid = left + (right - left) / 2; // 避免溢出

  if (nums[mid] == target) {
    return mid; // 直接返回索引
  } else if (target < nums[mid]) {
    return binary_search_recursion(nums, left, mid - 1, target); // 递归左半区间
  } else {
    return binary_search_recursion(nums, mid + 1, right, target); // 递归右半区间
  }
}

/* 折半查找（对有序线性表）：迭代 */
int binary_search_iteration(vector<int> nums, int left, int right, int target) {
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target) {
      return mid;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  return -1;
}

void test_01() {
  vector<int> nums = {1, 2, 4, 5, 3, 7};
  nums.resize(10, 0);
  int i = sequential_search_with_sentinel(nums, 6, 3);

  cout << i << endl;
}

void test_02() {
  vector<int> nums = {2, 5, 7, 10, 12, 13, 17, 19, 25, 26, 30};

  cout << "递归实现：" << binary_search_recursion(nums, 0, nums.size() - 1, 12) << endl;
  cout << "迭代实现：" << binary_search_iteration(nums, 0, nums.size() - 1, 12) << endl;
}

int main() {
  // test_01();
  test_02();

  return 0;
}