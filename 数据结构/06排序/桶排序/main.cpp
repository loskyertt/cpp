#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

void bucket_sort(vector<int> nums) {
  int max_val = INT_MIN;
  int min_val = INT_MAX;

  for (int num : nums) {
    max_val = max(max_val, num);
    min_val = min(min_val, num);
  }

  int count = 4; // 桶的数量
  vector<vector<int>> buckets(count);

  int increment = (max_val - min_val) / count + 1; // 定义每个桶的值域范围

  // 依次把元素放入各个桶中
  // for (int num : nums) {
  //   if (num >= min_val && num < min_val + increment) {
  //     buckets[0].push_back(num);
  //   } else if (num >= min_val + increment && num < min_val + 2 * increment) { // 注意这里是 else if ，而不是 if ！！！
  //     buckets[1].push_back(num);
  //   } else if (num >= min_val + 2 * increment && num < min_val + 3 * increment) {
  //     buckets[2].push_back(num);
  //   } else {
  //     buckets[3].push_back(num);
  //   }
  // }

  // 更简洁的写法
  for (int num : nums) {
    int bucketIndex = min(int((num - min_val) / increment), count - 1);
    buckets[bucketIndex].push_back(num);
  }

  // 给每个桶中的元素排序
  for (vector<int> &bucket : buckets) {
    sort(bucket.begin(), bucket.end());
  }

  cout << "桶排序结果：";
  for (vector<int> bucket : buckets) {
    for (int val : bucket) {
      cout << val << " ";
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

  bucket_sort(nums);
}

int main() {
  test();

  return 0;
}