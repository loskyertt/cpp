#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/* 计数排序 */
void count_sort(vector<int> &nums) {
  int max_val = INT_MIN;
  int min_val = INT_MAX;
  for (int num : nums) {
    max_val = max(max_val, num);
    min_val = min(min_val, num);
  }

  // 计数数组的大小，这种方式可以处理数组中含负数元素的情况，
  int n = max_val - min_val + 1;
  vector<int> count(n, 0);

  // 比如 min_val=-2，max_val=4，那么 n = 7。此时 min_val 在 count 数组中的索引为 0，max_val 在 count 数组中的索引为 6。
  for (int num : nums) {
    count[num - min_val]++;
  }

  cout << "排好序的数组为：";
  for (int i = 0; i < n; i++) {
    // 这种方式可以处理输出重复元素
    while (count[i]) {
      cout << i + min_val << " ";
      count[i]--;
    }
  }

  cout << endl;
}

void test() {
  vector<int> nums = {2,
                      5,
                      7,
                      1,
                      4,
                      6, -2, -4, -1, 10, 10, 8, 9, 14, 11};

  count_sort(nums);
}

int main() {
  test();

  return 0;
}