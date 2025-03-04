#include "graphAdjMat.hpp"

#include <climits>
#include <iostream>
#include <stdexcept>

/* 构造方法*/
GraphAdjMat::GraphAdjMat(
    const vector<char> &vertices,
    const vector<vector<int>> &edges) {
  // 添加顶点
  for (char val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const vector<int> &edge : edges) {
    add_edge(edge[0], edge[1], edge[2]);
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

  adjMat.emplace_back(vector<int>(n, INT_MAX));
  for (auto &row : adjMat) { // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
    row.push_back(INT_MAX);
  }
}

/* 删除顶点 */
void GraphAdjMat::remove_vertex(int index) {

  if (index >= size()) {
    throw out_of_range("顶点不存在");
  }

  vertices.erase(vertices.begin() + index); // 删除顶点

  adjMat.erase(adjMat.begin() + index);

  for (auto &row : adjMat) {
    row.erase(row.begin() + index);
  }
}

/* 添加边 */
void GraphAdjMat::add_edge(int i, int j, int w) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = w;
}

/* 删除边 */
void GraphAdjMat::remove_edge(int i, int j) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = INT_MAX;
}

/* 打印邻接矩阵 */
void GraphAdjMat::print() {
  cout << "顶点：" << endl;
  for (char vertex : vertices) {
    cout << vertex << " ";
  }

  cout << "\n"
       << endl;

  cout << "邻接矩阵为：" << endl;
  for (const auto &row : adjMat) {
    for (int val : row) {
      if (val == INT_MAX) {
        cout << "∞ "; // 让不可达的边更直观
      } else {
        cout << val << " ";
      }
    }
    cout << endl;
  }
}
