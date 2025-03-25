#include "arr.hpp"
#include <iostream>

using std::cout;
using std::endl;

/* 打印数组 */
void print_vector(vector<int> nums) {
  for (int num : nums) {
    cout << num << " ";
  }

  cout << endl;
}

/* 合并；两个有序数组 */
vector<int> merege_array(vector<int> &L1, vector<int> &L2) {

  vector<int> res;
  int i = 0, j = 0;
  while (i < L1.size() && j < L2.size()) {
    if (L1[i] < L2[j]) {
      res.push_back(L1[i]);
      i++;
    } else if (L1[i] > L2[j]) {
      res.push_back(L2[j]);
      j++;
    } else {
      res.push_back(L1[i]);
      i++;
      j++;
    }
  }

  while (i < L1.size()) {
    res.push_back(L1[i++]);
  }

  while (j < L2.size()) {
    res.push_back(L2[j++]);
  }

  return res;
}
