#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (int num : nums) {
    cout << num << " ";
  }

  cout << endl;
}

/* 把所有奇数移动到所有偶数的前边：双指针法 */
void move_nums_01(vector<int> &nums) {
  int n = nums.size();
  int j = n - 1;

  for (int i = 0; i < j; i++) {
    if (nums[i] % 2 == 0) {
      // 从后往前找奇数
      while (nums[j] % 2 == 0 && i < j) {
        j--;
      }
      swap(nums[i], nums[j]);
    }
  }
}

/* 双指针法 */
void move_nums_02(vector<int> &nums) {
  int i = 0;
  int j = nums.size() - 1;
  while (i < j) {
    // i 指针向右走，直到找到偶数
    while (nums[i] % 2 != 0) {
      i++;
    }
    // j 指针向左走，直到找到奇数
    while (nums[j] % 2 == 0) {
      j--;
    }

    if (i < j) {
      swap(nums[i], nums[j]);
    }
  }
}

void test_01() {
  // vector<int> nums = {1, 2, 4, 3, 7, 8, 5, 9, 6};
  vector<int> nums = {2, 4, 6, 1, 3, 5, 7};

  cout << "初始数组：";
  print_vector(nums);

  cout << "处理后的数组：";
  move_nums_01(nums);
  print_vector(nums);
}

void test_02() {
  // vector<int> nums = {1, 2, 4, 3, 7, 8, 5, 9, 6};
  vector<int> nums = {2, 4, 6, 1, 3, 5, 7};

  cout << "初始数组：";
  print_vector(nums);

  cout << "处理后的数组：";
  move_nums_02(nums);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}