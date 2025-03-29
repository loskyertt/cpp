#include "graphAdjMat.hpp"
#include <iostream>
#include <vector>

/* 查找 EL 路径 */
int is_exist_EL(vector<vector<int>> adjMat) {
  int n = adjMat.size();

  int odd_degree = 0;
  for (auto row : adjMat) {
    int count = 0;
    for (auto val : row) {
      count += val;
    }
    if (count % 2 == 1) {
      odd_degree++;
    }
  }

  if (odd_degree <= 2 && odd_degree % 2 == 0) {
    return 1;
  }

  return 0;
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

  vector<vector<int>> adjMat = graph.get_adjMat();

  int res = is_exist_EL(adjMat);

  if (res) {
    cout << "图 G 存在 EL 路径！" << endl;
  } else {
    cout << "图 G 不存在 EL 路径！" << endl;
  }
}

int main() {
  test();

  return 0;
}