#pragma once

#include <vector>

using namespace std;

/* 邻接矩阵 */
class GraphAdjMat {
  vector<char> vertices;      // 顶点列表
  vector<vector<int>> adjMat; // 邻接矩阵，行列索引对应“顶点索引”

  // 获取顶点列表中元素索引
  int get_index(char val);

public:
  /* 构造方法*/
  GraphAdjMat(const vector<char> &vertices, const vector<vector<char>> &edges);

  /* 获得邻接矩阵 */
  vector<vector<int>> get_adjMat();
  /* 获取顶点数量 */
  int size() const;
  /* 添加顶点 */
  void add_vertex(char val);
  /* 删除顶点 */
  void remove_vertex(int index);
  /* 添加边 */
  void add_edge(int i, int j); // 参数 i，j 对应 vertices 元素索引
  /* 删除边 */
  void remove_edge(int i, int j);
  /* 打印邻接矩阵 */
  void print();
};
