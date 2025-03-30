#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

/* 求邻接矩阵中各顶点的入度 */
vector<int> get_indegree(vector<vector<int>> &adjMat) {
  vector<int> indegree(adjMat.size(), 0);

  for (int i = 0; i < adjMat.size(); i++) {
    for (int j = 0; j < adjMat.size(); j++) {
      if (adjMat[j][i] == 1) {
        indegree[i]++;
      }
    }
  }

  return indegree;
}

void test_temp() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<vector<char>> edges = {{'a', 'c'},
                                {'a', 'b'},
                                {'a', 'd'},
                                {'c', 'd'},
                                {'d', 'e'},
                                {'b', 'e'},
                                {'b', 'f'}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  vector<vector<int>> adjMat = graph.get_adjMat();
  vector<int> indegree = get_indegree(adjMat);

  cout << "入度：";
  for (int val : indegree) {
    cout << val << " ";
  }
  cout << endl;
}

void test() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<vector<char>> edges = {{'a', 'c'},
                                {'a', 'b'},
                                {'a', 'd'},
                                {'c', 'd'},
                                {'d', 'e'},
                                {'b', 'e'},
                                {'b', 'f'}};

  GraphAdjMat graph(vertices, edges);

  graph.print();

  cout << "拓扑排序：";
  vector<char> res = graph.topology_sort();
  for (char val : res) {
    cout << val << " ";
  }
  cout << "\n"
       << endl;

  bool check = graph.is_unique_Topology_seq();
  if (check) {
    cout << "存在唯一的拓扑序列！";
  } else {
    cout << "不存在！" << endl;
  }
}

int main() {
  test();
  cout << endl;
  test_temp();

  return 0;
}