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

/* 基数排序，稳定 */

/* 测试 */
void test_01() {
  vector<int> nums = {13, 6, 3, 31, 9, 27, 5, 11, 2, 15};

  cout << "初始数组：";
  print_vector(nums);

  cout << "基数排序后的数组：";

  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;

  return 0;
}