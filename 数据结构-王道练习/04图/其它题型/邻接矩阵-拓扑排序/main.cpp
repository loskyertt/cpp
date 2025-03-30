#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

void test() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
  vector<vector<char>> edges = {{'a', 'b'},
                                {'a', 'f'},
                                {'a', 'g'},
                                {'c', 'a'},
                                {'c', 'd'},
                                {'d', 'f'},
                                {'f', 'e'},
                                {'g', 'e'}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  vector<int> indegree = graph.get_indegree();

  for (int val : indegree) {
    cout << val << " ";
  }

  cout << endl;

  vector<char> topology_res = graph.topology_sort();
  cout << "拓扑排序：";
  for (char val : topology_res) {
    cout << val << " ";
  }
  cout << endl;
}

int main() {
  test();

  return 0;
}