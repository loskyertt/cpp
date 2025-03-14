#include "graphAdjMat.hpp"
#include <climits>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

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
  // 初始化 indegree 列表
  indegree.resize(vertices.size(), 0);

  // 添加顶点
  for (char val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const auto &edge : edges) {
    int src = get_index(edge[0]);
    int dist = get_index(edge[1]);
    add_edge(src, dist);

    // 添加入度
    indegree[dist]++;
  }
}

/* 获得邻接矩阵 */
vector<vector<int>> GraphAdjMat::get_adjMat() {
  return adjMat;
}

/* 获取入度列表 */
vector<int> GraphAdjMat::get_indegree() {
  return indegree;
}

/* 获取顶点数量 */
int GraphAdjMat::size() const { return vertices.size(); }

/* 添加顶点 */
void GraphAdjMat::add_vertex(char val) {

  int n = size();

  vertices.push_back(val);
  adjMat.emplace_back(vector<int>(n, INT_MAX));

  int i = 0;
  for (auto &row : adjMat) { // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
    row.push_back(INT_MAX);
    row[i] = 0;
    i++;
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
      if (val == INT_MAX) {
        cout << "∞" << " ";
      } else {
        cout << val << " ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

/* 拓扑排序 */
vector<char> GraphAdjMat::topology_sort() {
  vector<char> res;
  queue<int> q;
  for (int i = 0; i < size(); i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int index = q.front();
    q.pop();

    res.push_back(vertices[index]);

    for (int j = 0; j < size(); j++) {
      if (adjMat[index][j] == 1) {
        indegree[j]--;
        if (indegree[j] == 0) {
          q.push(j);
        }
      }
    }
  }

  return res;
}