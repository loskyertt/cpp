#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

/* 方式一 */
void remove_target_num(vector<int> &nums, int target) {
  int j = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] != target) {
      // 把要删除的元素用后面的元素覆盖掉
      nums[j] = nums[i]; // 只保留不等于 x 的元素
      j++;
    }
  }

  nums.resize(j);
}

/* 还可以改变问题，删除值为 [s, t] 这个范围的元素，但是逻辑是一样的 */
void remove_area_num(vector<int> &nums, int s, int t) {
  if (nums.empty() || s > t) {
    throw out_of_range("数据有问题！");
  }

  int j = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] < s || nums[i] > t) {
      nums[j] = nums[i];
      j++;
    }
  }

  nums.resize(j);
}

void test_01() {
  vector<int> nums = {1, 3, 4, 4, 5, 6, 4, 8, 4, 10};
  int target = 4;

  cout << "原数组：";
  print_vector(nums);

  cout << "删除后的：";
  remove_target_num(nums, target);
  print_vector(nums);
}

void test_02() {
  vector<int> nums = {1, 3, 4, 4, 5, 6, 4, 8, 4, 10};
  int s = 3, t = 6;

  cout << "原数组：";
  print_vector(nums);

  cout << "删除后的：";
  remove_area_num(nums, s, t);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}