#include "graphAdjMat.hpp"

using namespace std;

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

int main() {

  test_GraphAdjMat();

  return 0;
}