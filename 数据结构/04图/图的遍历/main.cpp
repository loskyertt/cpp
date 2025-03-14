#include "graphAdjLinkedList.hpp"
#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

using namespace std;

// 邻接矩阵的 dfs 遍历和 bfs 遍历
void test_GraphAdjMat() {

  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {{0, 1}, // {src_index, dist_index}
                               {0, 3},
                               {1, 2},
                               {2, 3},
                               {2, 4},
                               {3, 4}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  graph.dfs(0);

  graph.bfs(0);

  cout << endl;
}

// 邻接链表的 dfs 和 bfs 遍历
void test_GraphAdjLinkedList() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  vector<vector<int>> edges = {{0, 1}, // {src, dist}
                               {0, 5},
                               {0, 6},
                               {2, 0},
                               {2, 3},
                               {3, 5},
                               {5, 4},
                               {6, 4}};

  GraphAdjLinkedList graph(vertices, edges);

  graph.print();

  graph.dfs(2);

  graph.bfs(2);
}

int main() {

  test_GraphAdjMat();
  test_GraphAdjLinkedList();

  return 0;
}