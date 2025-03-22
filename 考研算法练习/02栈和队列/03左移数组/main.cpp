#include <iostream>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

// 反转数组的辅助函数
void reverse(vector<int> &arr, int start, int end) {
  while (start < end) {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

/* 循环左移数组中的元素 */
void left_rotate(vector<int> &arr, int p) {
  int n = arr.size();
  if (p <= 0 || p > n) {
    throw out_of_range("p 不符合要求！");
  }

  // 反转前 p 个元素
  reverse(arr, 0, p - 1);

  // 反转后 n-p 个元素
  reverse(arr, p, n - 1);

  // 反转整个数组
  reverse(arr, 0, n - 1);
}

/* 循环左移数组中的元素：栈实现 */
void left_rotate_stack(vector<int> &arr, int p) {
  int n = arr.size();
  if (p <= 0 || p > n) {
    throw out_of_range("p 不符合要求！");
  }

  stack<int> s;

  for (int i = 0; i < n - p - 1; i++) {
    s.push(arr[i]);
  }

  int start = 0;
  for (int j = n - p - 1; j < n; j++) {
    arr[start++] = arr[j];
  }

  int end = n - 1;
  while (!s.empty()) {
    arr[end--] = s.top();
    s.pop();
  }
}

void test_01() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

  int p = 3;

  left_rotate(arr, p);
  // left_rotate(arr, p);

  cout << "反转后的数组为：" << endl;
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

void test_02() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

  int p = 3;

  left_rotate_stack(arr, p);

  cout << "反转后的数组为：" << endl;
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;
}

int main() {
  test_01();
  test_02();

  return 0;
}