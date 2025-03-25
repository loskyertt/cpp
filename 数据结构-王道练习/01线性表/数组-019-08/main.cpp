#include <algorithm>
#include <climits>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

/* 折半插入元素 */
void binary_insert(vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1;
  int pos = -1;

  // 二分查找找到目标位置
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (nums[mid] < target) {
      left = mid + 1;
    } else if (nums[mid] > target) {
      right = mid - 1;
    } else {
      pos = mid;
      break;
    }
  }

  if (pos != -1) {
    // 找到了元素，与下一个位置交换（如果不是最后一个元素）
    if (pos + 1 < nums.size()) {
      swap(nums[pos], nums[pos + 1]);
      cout << target << " 已找到并与下一个元素交换位置！" << endl;
    } else {
      cout << target << " 在最后一个位置！" << endl;
    }
  } else {
    // 元素不在数组中，插入到适当位置
    nums.insert(nums.begin() + left, target);
    cout << target << " 不在数组中，已插入到合适位置！" << endl;
  }
}

void test_01() {
  vector<int> nums = {1, 3, 5, 6, 8, 10};
  cout << "初始数组：";
  print_vector(nums);

  binary_insert(nums, 11);
  cout << "交换位置（或者插入 x）后的：";
  print_vector(nums);
}

int main() {
  test_01();

  return 0;
}