#include "graphAdjMat.hpp"
#include <climits>
#include <iostream>
#include <stdexcept>

GraphAdjMat::GraphAdjMat(
    const vector<int> &vertices,
    const vector<vector<int>> &edges) {
  // 添加顶点
  for (int val : vertices) {
    add_vertex(val);
  }

  // 添加边
  for (const vector<int> &edge : edges) {
    add_edge(edge[0], edge[1], edge[2]);
  }
}

int GraphAdjMat::size() const { return vertices.size(); }

void GraphAdjMat::add_vertex(int val) {

  int n = size();
  vertices.push_back(val);

  adjMat.emplace_back(vector<int>(n, 0));
  for (auto &row : adjMat) { // 注意这里 row 前要加 &，因为 row 是一个拷贝，auto row : adjMat 不会修改原始的 adjMat
    row.push_back(0);
  }
}

void GraphAdjMat::remove_vertex(int index) {

  if (index >= size()) {
    throw out_of_range("顶点不存在");
  }

  adjMat.erase(adjMat.begin() + index);

  for (auto &row : adjMat) {
    row.erase(row.begin() + index);
  }
}

void GraphAdjMat::add_edge(int i, int j, int weight) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = weight;
  adjMat[j][i] = weight;
}

void GraphAdjMat::remove_edge(int i, int j) {
  // 索引越界与相等处理
  if (i < 0 || j < 0 || i >= size() || j >= size() || i == j) {
    throw out_of_range("顶点不存在");
  }

  adjMat[i][j] = 0;
  adjMat[j][i] = 0;
}

void GraphAdjMat::print() {
  cout << "顶点：" << endl;
  for (int vertex : vertices) {
    cout << vertex << " ";
  }

  cout << "\n"
       << endl;

  cout << "邻接矩阵为：" << endl;
  for (auto row : adjMat) {
    for (auto val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
}

void GraphAdjMat::prim_MST() {
  vector<int> key(vertices.size(), INT_MAX);  // key[i]：存储每个节点到当前 MST 的最小权重
  vector<int> parent(vertices.size(), -1);    // parent[i]：存储 MST 中的父节点
  vector<bool> inMST(vertices.size(), false); // inMST[i]：标记顶点是否在生成树中

  key[0] = 0; // 从顶点 0 开始

  for (int count = 0; count < vertices.size() - 1; count++) {

    // 找到未加入 MST 的最小权重顶点
    int u = -1, minValue = INT_MAX;
    for (int i = 0; i < vertices.size(); i++) {
      if (!inMST[i] && key[i] < minValue) {
        minValue = key[i];
        u = i;
      }
    }

    inMST[u] = true; // 将该节点加入 MST

    // 更新相邻顶点的最小权重
    for (int v = 0; v < vertices.size(); v++) {
      if (adjMat[u][v] && !inMST[v] && adjMat[u][v] < key[v]) {
        key[v] = adjMat[u][v];
        parent[v] = u;
      }
    }
  }

  // 输出 MST
  cout << "\nMST 边 (父 -> 子, 权重):\n";
  for (int i = 1; i < vertices.size(); i++) {
    cout << parent[i] << " - " << i << "  权重: " << adjMat[i][parent[i]] << endl;
  }
}