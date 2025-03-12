#include "add.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

void print_vector(vector<int> nums) {
  for (auto num : nums) {
    cout << num << " ";
  }
  cout << endl;
}

void test_add() {
  cout << "你好，世界" << endl;

  cout << add(2, 3) << endl;
}

/* 测试自增 */
void test_self_add() {
  int i = 1;
  cout << "i++ = " << i++ << endl; // 先用后加
  cout << "i = " << i << endl;

  int j = 1;
  cout << "++j = " << ++j << endl; // 先加后用
}

/* 测试 vector 容器 */
void test_vector() {
  vector<int> nums = {1, 2, 3, 4, 5};

  cout << "Original nums: ";
  print_vector(nums);

  int index = 2;
  nums.erase(nums.begin() + index); // 删除索引处的元素
  cout << "Current nums: ";
  print_vector(nums);
}

/* 测试哈希表 */
void test_unordered_map() {
  unordered_map<int, string> map;
  /* 添加操作 */
  // 在哈希表中添加键值对 (key, value)
  map[12836] = "小哈";
  map[15937] = "小啰";
  map[16750] = "小算";
  map[13276] = "小法";
  map[10583] = "小鸭";

  cout << "size = " << map.size() << endl;

  cout << endl;

  for (auto [key, value] : map) {
    cout << key << " -> " << value << endl;
  }

  cout << endl;

  cout << "有 12836 吗？" << " " << map.count(12836) << endl;
  cout << "有 1836 吗？" << " " << map.count(1836) << endl;

  cout << endl;
}

int main() {
  // test_self_add();
  test_vector();
  // test_unordered_map();

  return 0;
}