#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

/* 枚举法：暴力求解 */
void get_intersection_enumerate(int *A, int *B, int lenA, int lenB) {
  vector<int> C;

  for (int i = 0; i < lenA; i++) {
    for (int j = 0; j < lenB; j++) {
      if (A[i] == B[j]) {
        C.push_back(A[i]);
      }
    }
  }

  cout << "枚举法查找结果：";
  for (int c : C) {
    cout << c << " ";
  }

  cout << endl;
}

/* 使用哈希表求解 */
void get_intersection_hash(int *A, int *B, int lenA, int lenB) {

  // unordered_set会将 A 数组中的所有元素插入到集合中，并自动处理去重
  // A：指向数组的起始位置（第一个元素）；A + lenA：指向数组的结束位置（最后一个元素的下一个位置）。
  unordered_set<int> setA(A, A + lenA);
  vector<int> C;

  for (int i = 0; i < lenB; i++) {
    // 对于 find() 方法，如果没有找到指定的元素（B[i]），它会返回 end() 迭代器。如果不相等的话，说明 B[i] 在集合 setA 中
    if (setA.find(B[i]) != setA.end()) {
      C.push_back(B[i]);
      setA.erase(B[i]); // 防止重复添加
    }
  }

  cout << "通过哈希表查找结果：";
  for (int c : C) {
    cout << c << " ";
  }

  cout << endl;
}

int main() {
  int A[5] = {1, 3, 4, 2, 7};
  int B[8] = {1, 2, 4, 9, 10, 8, 7, 6};

  get_intersection_enumerate(A, B, 5, 8);
  get_intersection_hash(A, B, 5, 8);

  return 0;
}