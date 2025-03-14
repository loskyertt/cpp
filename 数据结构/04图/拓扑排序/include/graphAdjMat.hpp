#pragma once

#include <vector>

using namespace std;

/* 邻接矩阵 */
class GraphAdjMat {
  vector<int> vertices;       // 顶点列表
  vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”
  vector<int> indegree;       // 记录顶点的入度，indegree 中的索引对应 vertices 中的索引

  /* 获取顶点索引 */
  int get_index(int target);

public:
  /* 构造方法*/
  GraphAdjMat(const vector<int> &vertices, const vector<vector<int>> &edges);

  /* 获得 indegree 列表 */
  vector<int> get_indegree();

  /* 获取顶点数量 */
  int size() const;

  /* 添加顶点 */
  void add_vertex(int val);

  /* 删除顶点 */
  void remove_vertex(int index);

  /* 添加边 */
  void add_edge(int i, int j); // 参数 i，j 对应 vertices 元素索引

  /* 删除边 */
  void remove_edge(int i, int j);

  /* 打印邻接矩阵 */
  void print();

  /* 拓扑排序 */
  vector<int> topology_sort();
};
