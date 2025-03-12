#include "graphAdjLinkedList.hpp"
#include "graphAdjListHash.hpp"
#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

using namespace std;

// 测试邻接矩阵
void test_GraphAdjMat() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {0, 1},
      {0, 3},
      {1, 2},
      {2, 3},
      {2, 4},
      {3, 4}};

  GraphAdjMat graph(vertices, edges);

  graph.print();
}

// 测试邻接表（hash 表实现）
void test_GraphAdjListHash() {
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjListHash graph(edges);

  graph.print();
}

void test_GraphAdjLinkedList() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjLinkedList graph(vertices, edges);

  cout << "初始图：" << endl;
  graph.print();

  // cout << "删除了边后的图：" << endl;
  // graph.remove_edge(1, 5);
  // graph.print();

  cout << "删除了顶点后的图：" << endl;
  graph.remove_vertex(1);
  graph.print();
}

int main() {

  test_GraphAdjMat();
  test_GraphAdjListHash();
  test_GraphAdjLinkedList();

  return 0;
}