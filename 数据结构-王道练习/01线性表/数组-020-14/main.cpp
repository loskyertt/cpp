#include <algorithm>
#include <climits>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

int find_min_distance(vector<int> A, vector<int> B, vector<int> C) {
  int minDist = INT_MAX;

  int i = 0, j = 0, k = 0;

  while (i < A.size() && j < B.size() && k < C.size() && minDist > 0) {
    int dist = abs(A[i] - B[j]) + abs(B[j] - C[k]) + abs(C[k] - A[i]);
    minDist = min(minDist, dist);

    if (A[i] <= B[j] && A[i] <= C[k]) {
      i++;
    } else if (B[j] <= A[i] && B[j] <= C[k]) {
      j++;
    } else {
      k++;
    }
  }

  return minDist;
}

/* 枚举法 */
int find_min_distance_enumerate(vector<int> A, vector<int> B, vector<int> C) {
  int min_distance = INT_MAX;
  for (int a : A) {
    for (int b : B) {
      for (int c : C) {
        int distance = abs(a - b) + abs(b - c) + abs(c - a);
        min_distance = min(distance, min_distance);
      }
    }
  }

  return min_distance;
}

int main() {
  vector<int> A = {-1, 0, 9};
  vector<int> B = {-25, -10, 10, 11};
  vector<int> C = {2, 9, 17, 30, 41};

  cout << "Minimum distance: " << find_min_distance(A, B, C) << endl;

  cout << "三元组最短距离（枚举法）：" << find_min_distance_enumerate(A, B, C) << endl;

  return 0;
}