#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/* 枚举法 */
int find_main_element_enumerate(vector<int> A) {

  for (int i = 0; i < A.size(); i++) {
    int count = 1;
    for (int j = 0; j < A.size(); j++) {
      if (j != i && A[i] == A[j]) {
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

  int max_val = *max_element(A.begin(), A.end());
  int min_val = *min_element(A.begin(), A.end());

  vector<int> B(max_val - min_val + 1, 0);

  for (int num : A) {
    B[num - min_val]++;
  }

  for (int i = 0; i < B.size(); i++) {
    if (B[i] > A.size() / 2) {
      return i + min_val;
    }
  }

  return -1;
}

void test() {
  vector<int> A = {0, 5, 5, 5, 1, 7, 5, 5};

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