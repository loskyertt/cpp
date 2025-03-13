#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

/* 找 K 点 */
int print_vertices(vector<vector<int>> adjMat, vector<char> vertices) {
  int K = 0;
  for (int i = 0; i < adjMat.size(); i++) {
    // 统计出度和入度
    int indegree = 0, outdegree = 0;
    for (int j = 0; j < adjMat.size(); j++) {
      // 对于邻接矩阵，出度在对应的行，入度在对应的列
      indegree += adjMat[j][i];
      outdegree += adjMat[i][j];
    }
    // 如果出度 > 入度，就输出顶点
    if (outdegree > indegree) {
      K++;
      cout << vertices[i] << " ";
    }
  }

  cout << endl;
  return K;
}

void test() {
  vector<char> vertices = {'a', 'b', 'c', 'd'};
  vector<vector<char>> edges = {
      {'a', 'b'},
      {'a', 'd'},
      {'b', 'd'},
      {'b', 'c'},
      {'c', 'd'}};

  GraphAdjMat graph(vertices, edges);

  // graph.print();

  vector<vector<int>> adjMat = graph.get_adjMat();

  int K = print_vertices(adjMat, vertices);
  cout << "K = " << K << endl;
}

int main() {
  test();

  return 0;
}