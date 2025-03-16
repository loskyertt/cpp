#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/* 测试标准库中的哈希表 */
void test_unordered_map() {
  unordered_map<int, string> map;

  /* 添加操作 */
  // 在哈希表中添加键值对 (key, value)
  map[12836] = "小哈";
  map[15937] = "小啰";
  map[16750] = "小算";
  map[13276] = "小法";
  map[10583] = "小鸭";

  // string name = map[12836];
  // cout << "name = " << name << endl;

  // for (auto kv : map) {
  //   cout << "key: " << kv.first << " " << "value: " << kv.second << endl;
  // }

  // 修改键值对
  map[10583] = "小白";

  // 删除键值对
  map.erase(16750);
  for (auto [key, value] : map) {
    cout << "key: " << key << " " << "value: " << value << endl;
  }

  cout << endl;
  if (map.find(10583) != map.end()) {
    cout << "有 10583" << endl;
  } else {
    cout << "没有！" << endl;
  }
}

int main() {
  test_unordered_map();

  return 0;
}