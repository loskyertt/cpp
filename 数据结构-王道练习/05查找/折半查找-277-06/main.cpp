#include <iostream>
#include <vector>

using namespace std;

/* 在矩阵中找目标元素 */
bool find_target(vector<vector<int>> &matrix, int target) {
  int n = matrix.size();
  int i = 0, j = n - 1;

  while (i < n && j > 0) {
    if (matrix[i][j] == target) {
      return true;
    } else if (matrix[i][j] < target) {
      i++;
    } else {
      j--;
    }
  }

  // 没找到
  return false;
}

void test() {
  // 矩阵特点：从左往右升序，从上往下升序
  vector<vector<int>> nums = {{1, 4, 7},
                              {2, 5, 8},
                              {3, 6, 9}};

  if (find_target(nums, 10)) {
    cout << "找到了！" << endl;
  } else {
    cout << "没找到！" << endl;
  }
}

int main() {
  test();

  return 0;
}