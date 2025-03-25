#include <algorithm>
#include <climits>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

/* 计数去重：限制太大 */
vector<int> remove_duplicate(vector<int> &nums) {
  int max_val = INT_MIN;
  int min_val = INT_MAX;
  for (int num : nums) {
    max_val = max(max_val, num);
    min_val = min(min_val, num);
  }

  int n = max_val - min_val + 1;
  vector<int> count(n, 0);
  vector<int> res;

  for (int num : nums) {
    count[num - min_val]++;
  }

  for (int i = 0; i < n; i++) {
    if (count[i] != 0) {
      res.push_back(i + min_val);
    }
  }

  return res;
}

/* 哈希去重 */
vector<int> remove_duplicate_hash(vector<int> &nums) {
  unordered_set<int> screen;
  vector<int> res;
  for (int num : nums) {
    // 相等代表没有重复元素
    if (screen.find(num) == screen.end()) {
      res.push_back(num);
    }
    screen.insert(num);
  }

  return res;
}

/* 如果顺序表是有序的 */
void remove_duplicate_insert(vector<int> &nums) {
  int i = 0, j = 1;
  while (j < nums.size()) {
    // 如果元素不相同，就把元素前移；相同的话就让 i 不动，j 移动，继续比较
    if (nums[i] != nums[j]) {
      nums[++i] = nums[j];
    }
    j++;
  }

  // i 指向的是数组索引（从 0 开始），所以最后返回的长度应该是 i+1
  nums.resize(i + 1);
}

void test_01() {
  vector<int> nums = {1, 3, 4, 4, 5, 6, 4, 8, 4, 10};
  cout << "初始数组：";
  print_vector(nums);

  cout << "去重后的数组：";
  vector<int> res = remove_duplicate(nums);
  print_vector(res);
}

void test_02() {
  vector<int> nums = {1, 3, 4, 4, 5, 6, 4, 8, 4, 10};
  cout << "初始数组：";
  print_vector(nums);

  cout << "去重后的数组：";
  vector<int> res = remove_duplicate_hash(nums);
  print_vector(res);
}

void test_03() {
  vector<int> nums = {1,
                      3,
                      3, 3, 4, 4, 5, 6, 8, 8, 10};
  cout << "初始数组：";
  print_vector(nums);

  cout << "去重后的数组：";
  remove_duplicate_insert(nums);
  print_vector(nums);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}