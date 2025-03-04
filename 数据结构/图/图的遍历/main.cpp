#include "graphAdjMat.hpp"
#include <vector>

using namespace std;

void test_GraphAdjMat() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  vector<vector<int>> edges = {
      {0, 1},
      {0, 3},
      {1, 2},
      {2, 5},
      {4, 5},
      {5, 6}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  graph.dfs(0);

  graph.bfs(0);
}

int main() {

  test_GraphAdjMat();

  return 0;
}