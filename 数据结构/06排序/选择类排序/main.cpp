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

/* 简单选择排序，不稳定 */
void simply_select_sort(vector<int> &nums) {
  for (int i = 0; i < nums.size() - 1; i++) { // 遍历所有元素（除了最后一个，最后一个不需要比较）
    int index = i;
    for (int j = i + 1; j < nums.size(); j++) { // 找到未排序部分的最小值
      if (nums[j] < nums[index]) {
        index = j; // 更新最小值索引
      }
    }
    swap(nums[i], nums[index]); // 交换当前元素和找到的最小值
  }
}

/* 堆排序：不稳定 */
// 自顶至底构建大顶堆
void sift_down(vector<int> &nums, int i, int end) {
  while (true) {
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;
    int max_index = i;
    if (left_index < end && nums[left_index] > nums[max_index]) {
      max_index = left_index;
    }
    if (right_index < end && nums[right_index] > nums[max_index]) {
      max_index = right_index;
    }
    if (max_index == i) {
      break;
    }

    swap(nums[i], nums[max_index]);
    i = max_index;
  }
}

void heap_sort(vector<int> &nums) {
  // 建堆操作：堆化除叶节点以外的其他所有节点
  for (int i = (nums.size() - 1 - 1) / 2; i >= 0; i--) {
    sift_down(nums, i, nums.size());
  }

  // 从堆中提取最大元素，循环 n-1 轮
  for (int i = nums.size() - 1; i > 0; i--) {
    // 交换根节点与最右叶节点（交换首元素与尾元素）
    swap(nums[i], nums[0]);
    // 以根节点为起点，从顶至底进行堆化
    sift_down(nums, 0, i);
  }
}

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "简单排序后的数组：";
  simply_select_sort(nums);
  print_vector(nums);
}

/* 测试 */
void test_02() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "堆排序后的数组：";
  heap_sort(nums);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}