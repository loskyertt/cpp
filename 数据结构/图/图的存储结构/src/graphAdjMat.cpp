#include "graphAdjMat.hpp"
#include <iostream>
#include <stdexcept>

/* 构造方法*/
GraphAdjMat::GraphAdjMat(const vector<int> &vertices,
                         const vector<vector<int>> &edges) {
  // 添加顶点
  for (int val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const vector<int> &edge : edges) {
    add_edge(edge[0], edge[1]);
  }
}

/* 获取顶点数量 */
int GraphAdjMat::size() const { return vertices.size(); }

/* 添加顶点 */
void GraphAdjMat::add_vertex(int val) {

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
  adjMat[j][i] = 1;
}

/* 删除边 */
void GraphAdjMat::remove_edge(int i, int j) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = 0;
  adjMat[j][i] = 0;
}

/* 打印邻接矩阵 */
void GraphAdjMat::print() {
  cout << "顶点：" << endl;
  for (int vertex : vertices) {
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