#include "graphAdjLinkedList.hpp"
#include <iostream>
#include <vector>

using namespace std;

void test_01() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjLinkedList graph(vertices, edges);

  cout << "初始图：" << endl;
  graph.print();

  vector<vector<int>> paths = graph.get_paths_bfs(1, 2);
  cout << "所有简单路径（bfs 实现）：" << endl;
  for (auto path : paths) {
    for (auto val : path) {
      cout << val << " -> ";
    }
    cout << endl;
  }
}

void test_02() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjLinkedList graph(vertices, edges);

  cout << "初始图：" << endl;
  graph.print();

  vector<vector<int>> paths = graph.get_paths_dfs(1, 2);
  cout << "所有简单路径（dfs 实现）：" << endl;
  for (auto path : paths) {
    for (auto val : path) {
      cout << val << " -> ";
    }
    cout << endl;
  }
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}