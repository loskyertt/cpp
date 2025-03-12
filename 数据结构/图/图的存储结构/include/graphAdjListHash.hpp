#pragma once

#include <unordered_map>
#include <vector>

using namespace std;

/* 邻接表（哈希表实现） */
class GraphAdjListHash {
  // 邻接表，key: 顶点，value: 该顶点的所有邻接顶点
  unordered_map<int, vector<int>> adjList; // <顶点, [所有邻接顶点]>

  /* 在 vector 中删除指定节点 */
  void remove(vector<int> &vertices, int vertex);

  /* 打印数组 */
  void print_vector(vector<int> vertices);

public:
  /* 构造方法 */
  GraphAdjListHash(const vector<vector<int>> &edges);

  /* 获取顶点个数 */
  int size();

  /* 添加边 */
  void add_edge(int src, int dist);

  /* 删除边 */
  void remove_edge(int src, int dist);

  /* 添加顶点 */
  void add_vertex(int vertex);

  /* 删除顶点 */
  void remove_vertex(int vertex);

  /* 打印邻接表 */
  void print();
};