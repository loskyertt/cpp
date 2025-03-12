#include "graphAdjListHash.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

// private:
/* 在 vector 中删除指定节点 */
void GraphAdjListHash::remove(vector<int> &vertices, int vertex) {
  for (int i; i < vertices.size(); i++) {
    if (vertices[i] == vertex) {
      vertices.erase(vertices.begin() + i);
      break;
    }
  }
}

/* 打印数组 */
void GraphAdjListHash::print_vector(vector<int> vertices) {
  cout << "[ ";
  for (auto vertex : vertices) {
    cout << vertex << " ";
  }
  cout << "]" << endl;
}

// public:
/* 构造方法 */
GraphAdjListHash::GraphAdjListHash(const vector<vector<int>> &edges) {
  // 添加所有顶点和边
  for (const vector<int> &edge : edges) {
    add_vertex(edge[0]);
    add_vertex(edge[1]);
    add_edge(edge[0], edge[1]);
  }
}

/* 获取顶点个数 */
int GraphAdjListHash::size() {
  return adjList.size();
}

/* 添加边 */
void GraphAdjListHash::add_edge(int src, int dist) {
  if (!adjList.count(src) || !adjList.count(dist) || src == dist) {
    throw out_of_range("不存在顶点");
  }
  // 添加边 src - dist
  adjList[src].push_back(dist);
  adjList[dist].push_back(src);
}

/* 删除边 */
void GraphAdjListHash::remove_edge(int src, int dist) {
  if (!adjList.count(src) || !adjList.count(dist) || src == dist) {
    throw out_of_range("不存在顶点");
  }
  // 删除边 src - dist
  remove(adjList[src], dist);
  remove(adjList[dist], src);
}

/* 添加顶点 */
void GraphAdjListHash::add_vertex(int vertex) {
  if (adjList.count(vertex)) {
    return;
  }
  // 在邻接表中添加一个新表
  adjList[vertex] = vector<int>();
}

/* 删除顶点 */
void GraphAdjListHash::remove_vertex(int vertex) {
  if (!adjList.count(vertex)) {
    throw out_of_range("不存在对应顶点！");
  }

  // 在邻接链表中删除顶点 vet 对应的链表
  adjList.erase(vertex);
  // 遍历其它顶点链表，删除所有包含 vet 的边
  for (auto &[key, value] : adjList) {
    remove(value, vertex);
  }
}

/* 打印邻接表 */
void GraphAdjListHash::print() {
  cout << "邻接表(Hash 表实现)：" << endl;
  for (const auto &[key, value] : adjList) {
    cout << key << " : ";
    print_vector(value);
  }
  cout << endl;
}
