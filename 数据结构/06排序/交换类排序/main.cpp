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

/* 冒泡排序：稳定 */
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

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "冒泡排序后的数组：";
  bubble_sort(nums);
  print_vector(nums);
}

int main() {
  test_01();

  return 0;
}