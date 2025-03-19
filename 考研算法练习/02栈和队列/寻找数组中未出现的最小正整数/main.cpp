#include <cstdlib>
#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/* 通过哈希表来实现 */
int find_missing_positive(vector<int> nums) {
  unordered_set<int> numSet;

  for (int num : nums) {
    if (num > 0) {
      numSet.insert(num);
    }
  }

  int missing = 1;
  while (numSet.find(missing) != numSet.end()) {
    missing++;
  }

  return missing;
}

/* 通过原地哈希表实现 */
int find_missing_positive_Situ(vector<int> nums) {
  int n = nums.size();

  // 排除负数和零的干扰，因为它们不可能是我们要找的最小正整数
  // 为什么是 n+1？因为缺失的最小正整数最大可能是 n+1（当数组正好包含 1~n 时），而替换后的 n+1 不会影响后续步骤
  for (int i = 0; i < n; i++) {
    if (nums[i] <= 0) {
      nums[i] = n + 1;
    }
  }

  // 把 nums 想象成抽屉（数字 1 是放在索引 0 处，数字 2 是放在索引 1 处 ......）。如果这个数(num)出现过，就在它本身的那个位置（与索引对应的位置）做一个标记（把标记处的数字转为负数），比如当遍历到 i = 1时，那么 num = 3，则对应的索引就是 2，把 2 处的数字标为负，就代表 3 出现过。所以说“负数”只是一个“信号”，表示该抽屉对应的数字存在。例如，抽屉 2 被标记为负，说明数字 3 存在。
  for (int i = 0; i < n; i++) {
    int num = abs(nums[i]);
    if (num <= n) {
      nums[num - 1] = -abs(nums[num - 1]);
    }
  }

  for (int i = 0; i < n; i++) {
    if (nums[i] > 0) { // 大于 0 表示这个位置没有被标记过，说明对应这个位置的数字就没出现过，因为对于数组的索引而言，是从小到大遍历的，此时这个索引再加上 1 就是对应的“未出现过的最小数字”
      return i + 1;
    }
  }

  return n + 1; // 所有抽屉都被标记，返回 n+1
}

void test() {
  vector<int> arr = {-5, 3, 2, 3};

  // cout << "最小未出现的正整数：" << find_missing_positive(arr) << endl;
  cout << "最小未出现的正整数：" << find_missing_positive_Situ(arr) << endl;
}

int main() {

  test();

  return 0;
}