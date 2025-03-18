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

/* 堆排序：见“建堆”，不稳定 */

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "简单排序后的数组：";
  simply_select_sort(nums);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;

  return 0;
}