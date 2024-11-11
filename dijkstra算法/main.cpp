#include "func.h"

int main() {
  // 创建一个示例图
  int n = 6; // 节点数量
  vector<vector<Edge>> graph(n);

  // 添加边 (u, v, weight)
  graph[0].push_back({1, 4});
  graph[0].push_back({2, 2});
  graph[1].push_back({2, 5});
  graph[1].push_back({3, 10});
  graph[2].push_back({4, 3});
  graph[3].push_back({5, 11});
  graph[4].push_back({3, 4});
  graph[4].push_back({5, 8});

  // 执行 Dijkstra 算法
  int start = 0; // 起点
  dijkstra(start, graph);

  return 0;
}