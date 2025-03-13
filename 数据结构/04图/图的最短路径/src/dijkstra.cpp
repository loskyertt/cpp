#include "dijkstra.hpp"
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/* 用优先队列实现 */
vector<int> dijkstra(int start, vector<char> vertices, vector<vector<int>> adjMat) {
  int n = vertices.size();
  vector<int> min_distance(n, INT_MAX); // 记录最短路径
  vector<bool> visited(n, false);       // 记录是否访问过
  min_distance[start] = 0;

  // 优先队列，存储{当前最短路径，顶点索引}，按照路径升序排序
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.emplace(0, start);

  while (!pq.empty()) {
    auto [d, u] = pq.top();
    pq.pop();

    if (visited[u]) {
      continue;
    }
    visited[u] = true;

    // 遍历所有邻接点
    for (int v = 0; v < n; ++v) {
      if (adjMat[u][v] != INT_MAX && !visited[v]) {
        int newDist = min_distance[u] + adjMat[u][v];
        if (newDist < min_distance[v]) {
          min_distance[v] = newDist;
          pq.emplace(newDist, v);
        }
      }
    }
  }

  return min_distance;
}

int choose_index(vector<int> distance, vector<bool> visited, int size) {
  int min_distance = INT_MAX;
  int min_position = -1;

  for (int i = 0; i < size; i++) {
    if (distance[i] < min_distance && visited[i] == false) {
      min_distance = distance[i];
      min_position = i;
    }
  }

  return min_position;
}

/* 用数组实现 */
PathInfo dijkstra(int start, vector<vector<int>> adjMat) {
  int n = adjMat.size();

  // 下面三个数组的索引与 vertices 的索引相对应
  vector<int> distance(n, INT_MAX); // start （起点）到达每一个点的最短路径大小
  vector<bool> visited(n, false);   // 顶点是否已经访问过
  vector<int> path(n, -1);          // 路径：存放的是顶点的前一个节点

  // 初始化起点
  for (int i = 0; i < n; i++) {
    distance[i] = adjMat[start][i];
  }

  visited[start] = true; // 在初始化 distance 的时候，vertices[0] 就访问过了
  distance[start] = 0;   // 可以不要，但是为了保证逻辑严密性，还是加上

  int next; // 接下来要访问的那个顶点
  // 这里初始化 i 为 1，因为在一开始（初始化 distance）的时候，就已经完成填写了从 第0个顶点 直接到其它顶点的最短路径
  for (int j = 1; j < n; j++) {
    next = choose_index(distance, visited, n);
    visited[next] = true;
    for (int k = 0; k < n; k++) {
      // 这里加上判断条件 adjMat[next][k] != INT_MAX 的原因是：num + INT_MAX 会溢出。同时 adjMat[next][k] == INT_MAX 表示 next->k 不可达
      if (visited[k] == false && adjMat[next][k] != INT_MAX && distance[next] + adjMat[next][k] < distance[k]) {
        distance[k] = distance[next] + adjMat[next][k];
        path[k] = next;
      }
    }
  }

  // 优化 path 输出
  for (int m = 1; m < n; m++) {
    if (path[m] == -1) {
      path[m] = 0;
    }
  }

  PathInfo path_info;

  path_info.distance = distance;
  path_info.path = path;

  return path_info;
}