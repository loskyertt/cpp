#include "graphAdjMat.hpp"
#include <iostream>
#include <stdexcept>

// 获取顶点列表中元素索引
int GraphAdjMat::get_index(char val) {
  for (int i = 0; i < size(); i++) {
    if (vertices[i] == val) {
      return i;
    }
  }

  throw out_of_range("没有这个顶点！");
}

/* 构造方法*/
GraphAdjMat::GraphAdjMat(const vector<char> &vertices,
                         const vector<vector<char>> &edges) {
  // 添加顶点
  for (char val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const auto &edge : edges) {
    int src = get_index(edge[0]);
    int dist = get_index(edge[1]);
    add_edge(src, dist);
  }
}

/* 获得邻接矩阵 */
vector<vector<int>> GraphAdjMat::get_adjMat() {
  return adjMat;
}

/* 获取顶点数量 */
int GraphAdjMat::size() const { return vertices.size(); }

/* 添加顶点 */
void GraphAdjMat::add_vertex(char val) {

  int n = size();

  vertices.push_back(val);
  adjMat.emplace_back(vector<int>(n, 0));
  for (auto &row : adjMat) { // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
    row.push_back(0);
  }
}

/* 删除顶点 */
void GraphAdjMat::remove_vertex(int index) {

  if (index >= size()) {
    throw out_of_range("顶点不存在");
  }

  vertices.erase(vertices.begin() + index);
  adjMat.erase(adjMat.begin() + index);

  for (auto &row : adjMat) {
    row.erase(row.begin() + index);
  }
}

/* 添加边 */
void GraphAdjMat::add_edge(int i, int j) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = 1;
  // adjMat[j][i] = 1;
}

/* 删除边 */
void GraphAdjMat::remove_edge(int i, int j) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = 0;
  // adjMat[j][i] = 0;
}

/* 打印邻接矩阵 */
void GraphAdjMat::print() {
  cout << "顶点：" << endl;
  for (auto vertex : vertices) {
    cout << vertex << " ";
  }

  cout << "\n"
       << endl;

  cout << "邻接矩阵：" << endl;
  for (auto row : adjMat) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
  cout << endl;
}