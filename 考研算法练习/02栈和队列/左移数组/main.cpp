#include <iostream>
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

int main() {
  vector<int> arr = {1, 2, 3, 4, 5, 6, 7};

  int p = 3;

  left_rotate(arr, p);

  cout << "反转后的数组为：" << endl;
  for (int num : arr) {
    cout << num << " ";
  }
  cout << endl;

  return 0;
}