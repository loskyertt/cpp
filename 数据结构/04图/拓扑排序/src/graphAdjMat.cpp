#include "graphAdjMat.hpp"
#include <climits>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

// private:
/* 获取顶点索引 */
int GraphAdjMat::get_index(int target) {
  for (int i = 0; i < size(); i++) {
    if (vertices[i] == target) {
      return i;
    }
  }

  throw out_of_range("没有这个顶点！");
}

// public:
/* 构造方法*/
GraphAdjMat::GraphAdjMat(const vector<int> &vertices,
                         const vector<vector<int>> &edges) {

  // 初始化 degree 列表
  indegree.resize(vertices.size(), 0);

  // 添加顶点
  for (int val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const vector<int> &edge : edges) {
    int src_index = get_index(edge[0]);
    int dist_index = get_index(edge[1]);
    add_edge(src_index, dist_index);
    indegree[dist_index]++;
  }
}

/* 获得 indegree 列表 */
vector<int> GraphAdjMat::get_indegree() {
  return indegree;
}

/* 获取顶点数量 */
int GraphAdjMat::size() const {
  return vertices.size();
}

/* 添加顶点 */
void GraphAdjMat::add_vertex(int val) {

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
  for (int vertex : vertices) {
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
vector<int> GraphAdjMat::topology_sort() {
  vector<int> res;
  queue<int> q;

  // 把所有入度为 0 的顶点放到队列中
  for (int i = 0; i < size(); i++) {
    if (indegree[i] == 0) {
      q.push(i);
    }
  }

  while (!q.empty()) {
    int index = q.front();
    q.pop();
    res.push_back(vertices[index]);

    // 把 index 对应顶点（src 顶点）,i 对应的是 dist 顶点，因为访问过了，所以要让这些 dist 顶点的入度减一
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