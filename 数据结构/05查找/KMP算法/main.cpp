#include <iostream>
#include <string>
#include <vector>

using namespace std;

/* next 数组实现 */
vector<int> get_next(string &pattern) {
  int n = pattern.size();
  vector<int> next(n, 0);

  // j：前缀末尾，i：后缀末尾
  int j = 0;
  for (int i = 1; i < n; i++) {
    while (j > 0 && pattern[i] != pattern[j]) {
      j = next[j - 1]; // j 要跳回前一个匹配的最长前后缀长度所指的索引
    }
    if (pattern[j] == pattern[i]) {
      j++; // 回溯
    }

    next[i] = j; // 找到匹配的前缀
  }

  return next;
}

/* KMP 算法实现 */
int kmp(vector<int> &next, string match, string pattern) {
  int j = 0; // patter 的指针

  // i 是 match 的指针，永不回退
  for (int i = 0; i < match.size(); i++) {

    while (j > 0 && match[i] != pattern[j]) {
      j = next[j - 1]; // // 失配的话，就回溯
    }

    if (match[i] == pattern[j]) {
      j++;
    }

    if (j == pattern.size()) {
      return i - j + 1;
    }
  }

  return -1; // 未找到
}

void test_01() {
  string pattern = "ABCDABD";
  vector<int> next = get_next(pattern);

  cout << "next 数组为：";
  for (int num : next) {
    cout << num << " ";
  }

  cout << endl;
}

void test_02() {
  string match = "BBCABCDABABCDABCDABDE";
  string pattern = "ABCDABD";

  vector<int> next = get_next(pattern);

  int index = kmp(next, match, pattern);

  if (index) {
    cout << "从 match 的第 " << index << " 个位置开始匹配。" << endl;
  } else {
    cout << "无匹配字符串！" << endl;
  }
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}