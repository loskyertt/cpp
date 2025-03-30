#include "graphAdjLinkedList.hpp"
#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

// 测试邻接矩阵的拓扑排序
void test_01() {
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

  vector<int> res_bfs = graph.topology_sort_bfs();

  cout << "拓扑排序（邻接矩阵，bfs 实现）：";
  for (int val : res_bfs) {
    cout << val << " ";
  }

  cout << endl;

  vector<int> res_dfs = graph.topology_sort_dfs();

  cout << "拓扑排序（邻接矩阵，dfs 实现）：";
  for (int val : res_dfs) {
    cout << val << " ";
  }

  cout << endl;
}

// 测试邻接链表的拓扑排序
void test_02() {
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

  cout << "拓扑排序（邻接表）：";
  for (int val : topology_res) {
    cout << val << " ";
  }

  cout << endl;
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}