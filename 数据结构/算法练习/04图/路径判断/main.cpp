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

  bool res = graph.is_existed_path(3, 4);
  if (res) {
    cout << "存在路径！" << endl;
  } else {
    cout << "不存在路径！" << endl;
  }
}

int main() {
  test();

  return 0;
}