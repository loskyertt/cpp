#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/* 枚举法 */
// 这个实现能够避免重复计算已经检查过的元素值，但时间复杂度仍然是 O(n²)
int find_main_element_enumerate(vector<int> A) {
  for (int i = 0; i < A.size(); i++) {
    // 检查当前元素是否已经在之前的位置出现过
    bool seen_before = false;
    for (int k = 0; k < i; k++) {
      if (A[i] == A[k]) {
        seen_before = true;
        break;
      }
    }

    // 如果当前元素已经在之前出现过，跳过
    if (seen_before)
      continue;

    // 计算当前元素出现次数
    int count = 0;
    for (int j = 0; j < A.size(); j++) {
      if (A[i] == A[j]) {
        count++;
      }
    }

    if (count > A.size() / 2) {
      return A[i];
    }
  }

  return -1;
}

/* Boyer-Moore多数投票算法 */
// 算法的核心思想是 通过抵消不同元素 的方式来找到一个可能的主元素，如果序列中有一个元素的数量超过总数的一半，两个不相等的元素两两抵消，那么最终的 candidate 一定会是这个主元素！
int find_main_element_boyer_moore(vector<int> A) {
  int candidate = -1;
  int count = 0;

  // 第一遍遍历，找到候选主元素
  for (int num : A) {
    // 等于 0 说明还没有值
    if (count == 0) {
      candidate = num;
      count = 1;

    } else if (num == candidate) {
      count++;
    } else {
      count--;
    }
  }

  // 第二遍遍历，验证候选主元素是否为主元素
  count = 0;
  for (int num : A) {
    if (num == candidate) {
      count++;
    }
  }

  if (count > A.size() / 2) {
    return candidate;
  } else {
    return -1;
  }
}

/* 计数排序 */
int find_main_element_count_sort(vector<int> A) {
  if (A.empty())
    return -1;

  // max_element 和 min_element 是 C++ 标准库中的算法，用于在范围内（比如：[A.begin(), A.end()) 这个范围）找到最大值和最小值的迭代器，使用解引用运算符 * 可以获取迭代器指向的元素值。
  int max_val = *max_element(A.begin(), A.end());
  int min_val = *min_element(A.begin(), A.end());

  // B 数组的每个位置对应原数组中的一个可能的值，这样就可以统计每个值出现的次数。比如数组中的元素范围从3到7，那么max_val - min_val + 1就是5，刚好对应3、4、5、6、7这五个数。
  vector<int> B(max_val - min_val + 1, 0);

  for (int num : A) {
    // 这里的 num - min_val 就是为了对应到 B 数组中的索引（i），索引处的值就对应 num 出现的次数
    int i = num - min_val;
    B[i]++;
  }

  for (int i = 0; i < B.size(); i++) {
    if (B[i] > A.size() / 2) {
      // 最后要返回的是 num
      return i + min_val;
    }
  }

  return -1;
}

void test() {
  vector<int> A = {0, 1, 5, 5, 1, 7, 5, 5};

  // int m = find_main_element_enumerate(A);
  // int m = find_main_element_boyer_moore(A);
  int m = find_main_element_count_sort(A);

  if (m == -1) {
    cout << "无主元素" << endl;
  } else {
    cout << "m = " << m << endl;
  }
}

int main() {
  test();

  return 0;
}