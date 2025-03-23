#include <iostream>
#include <list>

using namespace std;

/* 打印 list 容器 */
void print_list(list<int> &nums) {
  for (list<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

/* 操作和 vector 基本一致 */
void test_01() {
  list<int> nums;
  nums.push_back(2);
  nums.push_back(5);
  nums.push_back(6);
  nums.push_back(7);
  nums.push_back(8);
  nums.push_back(9);

  cout << "初始 list 容器：" << endl;
  print_list(nums);
}

int main() {
  test_01();

  return 0;
}