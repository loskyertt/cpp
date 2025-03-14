#include "graphAdjLinkedList.hpp"
#include <iostream>
#include <vector>

void test() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  vector<vector<int>> edges = {{0, 1},
                               {0, 5},
                               {0, 6},
                               {2, 0},
                               {2, 3},
                               {3, 5},
                               {5, 4},
                               {6, 4}};

  GraphAdjLinkedList graph(vertices, edges);

  graph.print();

  // vector<Vertex *> adjList = graph.get_adjList();
  // vector<int> outdegree = graph.get_outdegree();
  // vector<int> indegree = graph.get_indegree();

  // cout << "出度：";
  // for (int val : outdegree) {
  //   cout << val << " ";
  // }
  // cout << endl;
  // cout << "入度：";
  // for (int val : indegree) {
  //   cout << val << " ";
  // }

  vector<int> topology_res = graph.topology_sort();

  cout << "拓扑排序：";
  for (int val : topology_res) {
    cout << val << " ";
  }

  cout << endl;
}

int main() {
  test();

  return 0;
}