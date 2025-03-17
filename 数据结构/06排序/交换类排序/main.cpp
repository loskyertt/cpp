#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> nums) {
  for (int num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

/* 冒泡排序，稳定 */
void bubble_sort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) { // i是每次减少比较的元素个数。最后一个元素不需要比较
    bool swapped = false;                     // 如果元素是有序的，最终的状态一定还是 false，那么就可以直接退出循环
    for (int j = 0; j < nums.size() - i - 1; j++) {
      if (nums[j] > nums[j + 1]) {
        swap(nums[j], nums[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

/* 快速排序，不稳定*/
// 哨兵分划
int get_pivot_index(vector<int> &nums, int left, int right) {
  int i = left, j = right; // 初始化左右指针
  int pivot = nums[left];  // 把左边第一个数作为哨兵
  while (i < j) {
    while (i < j && nums[j] >= pivot) {
      j--;
    }
    while (i < j && nums[i] <= pivot) {
      i++;
    }

    swap(nums[i], nums[j]);
  }

  // 最后 i 和 j 是相同的
  swap(nums[left], nums[i]);

  return i;
}

void quick_sort(vector<int> &nums, int left, int right) {
  if (left > right) {
    return;
  }

  int pivot_index = get_pivot_index(nums, left, right);

  quick_sort(nums, left, pivot_index - 1);
  quick_sort(nums, pivot_index + 1, right);
}

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "冒泡排序后的数组：";
  bubble_sort(nums);
  print_vector(nums);
}

/* 测试 */
void test_02() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "快速排序后的数组：";
  quick_sort(nums, 0, nums.size() - 1);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}