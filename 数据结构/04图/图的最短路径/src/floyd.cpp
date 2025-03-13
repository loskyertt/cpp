#include "floyd.hpp"
#include <climits>
#include <vector>

/* Floy 算法 */
vector<vector<int>> floyd(vector<vector<int>> adjMat) {
  int n = adjMat.size();

  vector<vector<int>> distance(n, vector<int>(n, 0)); // distance 数组，存放距离
  vector<vector<int>> path(n, vector<int>(n, 0));     // path 数组，存放前驱顶点

  // 初始化 distance 数组和 path 数组
  // j: 起始顶点，k: 终止顶点
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < n; k++) {
      distance[j][k] = adjMat[j][k]; // i 表示起点，j 表示终点
      path[j][k] = k;
    }
  }

  // i: 中转顶点，j: 起始顶点，k: 终止顶点 （i, j, k 都表示顶点在 vertices 数组中的索引）
  // 第一层循环：索引从 [0, n - 1] 依次作为中转顶点
  for (int i = 0; i < n; i++) {

    // 第二层和第三层循环构成二维数组，然后“填空”即可
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        // 若 直达 > 中转，更新 distance 和 path ; distance[j][i] 和 distance[i][k] 都为 INT_MAX 的话，表示不可达
        if (distance[j][i] != INT_MAX && distance[i][k] != INT_MAX && distance[j][k] > distance[j][i] + distance[i][k]) {
          distance[j][k] = distance[j][i] + distance[i][k];
          path[j][k] = path[j][i];
        }
      }
    }
  }

  return distance;
}