#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

/* 求三个数组交集：数组为等长递增有序数组 */
vector<int> get_intersection(vector<int> &A, vector<int> &B, vector<int> &C) {
  int n = A.size();
  vector<int> res;
  int i = 0, j = 0, k = 0;
  while (i < n && j < n && k < n) {
    if (A[i] == B[j] && B[j] == C[k]) {
      res.push_back(A[i]);
      i++;
      j++;
      k++;
    } else {
      // 将小的元素的数组的指针往后移一位
      int max_val = max(max(A[i], B[j]), C[k]);
      i = A[i] < max_val ? i + 1 : i;
      j = B[j] < max_val ? j + 1 : j;
      k = C[k] < max_val ? k + 1 : k;
    }
  }

  return res;
}

void test_01() {
  vector<int> A = {1, 3, 5, 6, 8, 10};
  vector<int> B = {2, 3, 5, 7, 8, 12};
  vector<int> C = {1, 3, 5, 4, 8, 9};

  vector<int> res = get_intersection(A, B, C);
  cout << "交集为：";
  print_vector(res);
}

int main() {
  test_01();

  return 0;
}