#include "graphAdjMat.hpp"

using namespace std;

void test_prim_MST() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5};
  vector<vector<int>> edges = {
      {0, 1, 6},
      {0, 2, 1},
      {0, 3, 5},
      {1, 2, 5},
      {2, 3, 4},
      {2, 4, 6},
      {1, 4, 3},
      {2, 5, 4},
      {4, 5, 6},
      {3, 5, 2},
  };

  GraphAdjMat graph(vertices, edges);

  graph.print();

  graph.prim_MST();
}

int main() {

  test_prim_MST();

  return 0;
}