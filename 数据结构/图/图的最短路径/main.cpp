#include "dijkstra.hpp"
#include "graphAdjMat.hpp"

#include <climits>
#include <iostream>

using namespace std;

void test_GraphAdjMat() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<vector<int>> edges = {
      {0, 1, 2},
      {0, 2, 5},
      {1, 2, 1},
      {1, 3, 3},
      {2, 3, 3},
      {2, 4, 4},
      {2, 5, 1},
      {3, 4, 1},
      {3, 5, 4},
      {4, 5, 1}};

  GraphAdjMat graph(vertices, edges);

  // graph.print();
  vector<vector<int>> adjMat = graph.get_adjMat();
  vector<int> dist = dijsktra(0, vertices, adjMat);
  cout << "从 A 到各顶点的最短路径：" << endl;
  for (size_t i = 0; i < dist.size(); i++) {
    cout << vertices[i] << ": " << (dist[i] == INT_MAX ? "∞" : to_string(dist[i])) << endl;
  }
}

int main() {

  test_GraphAdjMat();

  return 0;
}