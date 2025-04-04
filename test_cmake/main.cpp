#include "add.h"
#include <algorithm>
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

void print_matrix(vector<vector<int>> matrix) {
  for (auto row : matrix) {
    for (auto value : row) {
      cout << value << " ";
    }
    cout << endl;
  }
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
  vector<int> nums_1 = {1, 2, 3, 4, 5};

  cout << "Original nums: ";
  print_vector(nums_1);

  int index = 2;
  nums_1.erase(nums_1.begin() + index); // 删除索引处的元素
  cout << "Current nums: ";
  print_vector(nums_1);

  cout << endl;

  // 迭代器测试
  auto it = nums_1.begin();
  cout << "*it: " << *(it + 1) << endl;

  if (find(nums_1.begin(), nums_1.end(), 5) == nums_1.end()) {
    cout << "没有数字 5" << endl;
  } else {
    cout << "有数字 5" << endl;
  }

  cout << endl;

  vector<vector<int>> matrix = {
      {1, 2},
      {4, 5},
      {3, 4}};

  cout << "The size of matrix: " << matrix.size() << endl;

  cout << "New Matrix: " << endl;
  matrix.emplace_back(2, 0);

  print_matrix(matrix);

  cout << endl;

  // 插入示例
  vector<int> vertices;
  vertices.insert(vertices.end(), matrix[0].begin(), matrix[0].end());
  cout << "vertices: ";
  print_vector(vertices);

  cout << endl;

  // const vector<int> nums_2 = {1, 2, 3};
  // nums_1.push_back(2);  // ERROR!!!

  vector<int> nums_3;
  nums_3.push_back(2);

  cout << "nums : ";
  print_vector(nums_3);

  cout << endl;
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

  if (map.find(12836) != map.end()) {
    cout << "12836 在" << endl;
  }

  cout << endl;

  // 删除 12836 后
  map.erase(12836);
  cout << "删除 12836 后" << endl;
  for (auto [key, value] : map) {
    cout << key << " -> " << value << endl;
  }

  cout << endl;
}

/* 测试枚举 */
void test_enumerate() {
  enum spectrum { red,
                  yellow,
                  gree,
                  blue,
                  vplot };

  spectrum band;
  cout << band << endl;

  cout << yellow << endl;
}

void test_addr() {
  // int arr[5] = {1, 2, 3, 4, 5};

  // cout << "元素首地址(&arr[0]):" << &arr[0] << endl;
  // cout << "元素首地址(arr):" << arr << endl;
  // cout << "arr 地址:" << &arr << endl;

  // int a = 1;
  // int &p = a;

  // cout << "&a: " << &a << endl;
  // cout << "p = " << p << endl;
  // cout << "&p = " << &p << endl;

  int b = 2;
  int *pb = &b;

  cout << "*pb = " << *pb << endl;
  cout << "pb = " << pb << endl;
  cout << "&b = " << &b << endl;
  cout << "b = " << b << endl;
}

int main() {
  // test_self_add();
  // test_vector();
  // test_unordered_map();
  test_enumerate();
  // test_addr();

  return 0;
}