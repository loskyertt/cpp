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

/* 直接插入排序：方式一，稳定 */
// 效率比较低
void insert_sort_directly_01(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    for (int j = i - 1; j >= 0; j--) {
      // 如果当前元素比前一个元素小，就交换
      if (nums[j + 1] < nums[j]) {
        swap(nums[j + 1], nums[j]);
      } else {
        break;
      }
    }
  }
}

/* 直接插入排序：方式二，稳定 */
void insert_sort_directly_02(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    // 记录下 nums[i] 的值
    int tmp = nums[i];

    // i 前面的元素都是排好序的，从 i 前面的元素开始
    int j = i - 1;
    // 移动比 tmp 大的元素
    while (nums[j] > tmp && j >= 0) {
      nums[j + 1] = nums[j];
      j--;
    }

    // 插入 tmp
    nums[j + 1] = tmp;
  }
}

/* 折半插入排序，稳定 */
void insert_sort_binary(vector<int> &nums) {
  for (int i = 1; i < nums.size(); i++) {
    // 如果 nums[i] >= nums[i-1] ，直接去下一个数，因为前面的数都是有序的
    if (nums[i] >= nums[i - 1]) {
      continue;
    }
    int tmp = nums[i];
    int left = 0;
    int right = i - 1;
    // 通过折半查找，先定位到 tmp 的位置
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] <= tmp) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    // 把从 left 开始的元素都往后移动，给 tmp 腾出空间
    int j = i;
    while (j > left) {
      nums[j] = nums[j - 1];
      j--;
    }

    // 插入 tmp，tmp 一定是插到 left 处
    nums[left] = tmp;
  }
}

/* 希尔排序，不稳定 */
void shell_sort(vector<int> &nums) {
  // 定义增量
  int increment = nums.size() / 2;

  while (increment > 0) {
    // 对每个子序列进行处理：0 到 increment-1
    for (int i = 0; i < increment; i++) {
      // 对当前子序列进行插入排序
      for (int j = i + increment; j < nums.size(); j += increment) {
        int tmp = nums[j];
        int k = j - increment;

        while (k >= 0 && nums[k] > tmp) {
          nums[k + increment] = nums[k];
          k -= increment;
        }

        nums[k + increment] = tmp;
      }
    }

    increment /= 2;
  }
}

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2};

  cout << "初始数组：";
  print_vector(nums);

  insert_sort_directly_01(nums);

  cout << "直接插入排序后的数组（方式一）：";
  print_vector(nums);
}

/* 测试 */
void test_02() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2};

  cout << "初始数组：";
  print_vector(nums);

  insert_sort_directly_02(nums);

  cout << "直接插入排序后的数组（方式二）：";
  print_vector(nums);
}

/* 测试 */
void test_03() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2};

  cout << "初始数组：";
  print_vector(nums);

  insert_sort_binary(nums);

  cout << "折半插入排序后的数组：";
  print_vector(nums);
}

/* 测试 */
void test_04() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2};

  cout << "初始数组：";
  print_vector(nums);

  shell_sort(nums);

  cout << "希尔排序后的数组：";
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();
  cout << endl;
  test_04();

  return 0;
}
