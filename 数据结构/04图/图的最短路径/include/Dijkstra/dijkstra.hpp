#pragma once

#include <vector>

using namespace std;

struct PathInfo {
  vector<int> path;
  vector<int> distance;
};

/* 用优先队列实现 */
vector<int> dijkstra(int start, vector<char> vertices, vector<vector<int>> adjMat);

/* 用数组实现 */
PathInfo dijkstra(int start, vector<vector<int>> adjMat);