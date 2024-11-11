#include "func.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <queue>
#include <vector>

void dijkstra(int start, const vector<vector<Edge>> &graph) {
  int n = graph.size();              // 图的节点数量
  vector<int> distances(n, INT_MAX); // 初始化所有节点距离为无穷大
  vector<int> previous(n, -1);       // 用于存储路径的前驱节点
  priority_queue<Node> pq;           // 优先队列

  // 初始化起点
  distances[start] = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    Node current = pq.top();
    pq.pop();

    int currentVertex = current.vertex;
    int currentDistance = current.distance;

    // 如果当前距离已经不是最短距离，跳过
    if (currentDistance > distances[currentVertex])
      continue;

    // 遍历当前节点的所有边
    for (const Edge &edge : graph[currentVertex]) {
      int nextVertex = edge.to;
      int newDist = currentDistance + edge.weight;

      // 如果找到最短路径
      if (newDist < distances[nextVertex]) {
        distances[nextVertex] = newDist;
        previous[nextVertex] = currentVertex;
        pq.push({nextVertex, newDist});
      }
    }
  }

  // 输出结果
  cout << "Node\tDistance from Source\tPath" << endl;
  for (int i = 0; i < n; ++i) {
    cout << i << "\t" << distances[i] << "\t\t";

    // 打印路径
    if (distances[i] == INT_MAX) {
      cout << "No Path";
    } else {
      vector<int> path;
      for (int at = i; at != -1; at = previous[at]) {
        path.push_back(at);
      }
      reverse(path.begin(), path.end());
      for (int node : path) {
        cout << node << " ";
      }
    }
    cout << endl;
  }
}