#include "graphAdjLinkedList.hpp"
#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

// 测试邻接矩阵的拓扑排序
void test_GraphAdjMat() {
  vector<int> vertices = {0, 1, 2, 3, 4, 5, 6};
  vector<vector<int>> edges = {{0, 1},
                               {0, 5},
                               {0, 6},
                               {2, 0},
                               {2, 3},
                               {3, 5},
                               {5, 4},
                               {6, 4}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  // vector<int> indegree = graph.get_indegree();

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

// 测试邻接链表的拓扑排序
void test_GraphAdjLinkedList() {
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

  vector<int> indegree = graph.get_indegree();

  // cout << "入度：";
  // for (int val : indegree) {
  //   cout << val << " ";
  // }

  // cout << endl;

  vector<int> topology_res = graph.topology_sort();

  cout << "拓扑排序：";
  for (int val : topology_res) {
    cout << val << " ";
  }

  cout << endl;
}

int main() {
  test_GraphAdjMat();
  cout << endl;
  test_GraphAdjLinkedList();

  return 0;
}