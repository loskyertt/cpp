#include <iostream>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> nums) {
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

/* 合并两个有序数组 */
void merge(vector<int> &nums, int left, int mid, int right) {
  // 左子数组区间为 [left, mid], 右子数组区间为 [mid+1, right]
  // 创建一个临时数组 tmp ，用于存放合并后的结果
  vector<int> tmp(right - left + 1, 0);

  // 初始化左子数组和右子数组的起始索引，k 为 tmp 数组索引
  int i = left, j = mid + 1, k = 0;

  while (i <= mid && j <= right) {
    if (nums[i] < nums[j]) {
      tmp[k++] = nums[i++];
    } else {
      tmp[k++] = nums[j++];
    }
  }

  while (i <= mid) {
    tmp[k++] = nums[i++];
  }

  while (j <= right) {
    tmp[k++] = nums[j++];
  }

  for (int i = 0; i < tmp.size(); i++) {
    nums[i + left] = tmp[i];
  }
}

/* 归并排序，稳定 */
void merge_sort(vector<int> &nums, int left, int right) {
  if (left >= right) {
    return; // 当子数组长度为 1 时终止递归
  }

  int mid = left + (right - left) / 2;

  merge_sort(nums, left, mid);
  merge_sort(nums, mid + 1, right);

  merge(nums, left, mid, right);
}

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "归并排序后的数组：";
  merge_sort(nums, 0, nums.size() - 1);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;

  return 0;
}