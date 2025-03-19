#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::for_each;
using std::vector;

void my_print(int val) {
  cout << val << " ";
}

void test_01() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  vector<int>::iterator it_begin = nums.begin();

  cout << "*it_begin : " << *it_begin << endl;
  cout << "nums[0] 的地址：" << &nums[0] << endl;
  cout << "it_begin 所指向的地址：" << &(*it_begin) << endl;

  cout << endl;

  vector<int>::iterator it_end = nums.end();
  cout << "*it_end : " << *it_end << endl; // 打印出的是随机数字，nums.end() 指向的是 nums[n-1] 的下一个位置

  cout << endl;
}

void test_02() {
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};

  vector<int>::iterator it_begin = nums.begin();
  vector<int>::iterator it_end = nums.end();

  cout << "遍历方式一：";
  while (it_begin != it_end) {
    cout << *it_begin << " ";
    it_begin++;
  }

  // 这是错误写法，会陷入死循环！nums.begin 不是一个变量，而是一个函数调用，每次 nums.begin() 都会返回一个 新的临时迭代器 指向 nums 的开头！
  // while (nums.begin() != nums.end()) {
  //   cout << *nums.begin() << " ";
  //   nums.begin()++;
  // }

  cout << endl;

  cout << "遍历方式二：";
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;

  // 第三种遍历方式：
  // 使用STL提供标准遍历算法 头文件 algorithm
  cout << "遍历方式三：";
  for_each(nums.begin(), nums.end(), my_print);
}

int main() {
  test_01();
  test_02();

  return 0;
}