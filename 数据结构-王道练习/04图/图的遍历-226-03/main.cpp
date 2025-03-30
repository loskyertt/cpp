#include "graphAdjLinkedList.hpp"
#include <functional>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/* 获得图的顶点索引 */
int get_index(int val, vector<int> &vertices) {
  for (int i = 0; i < vertices.size(); i++) {
    if (val == vertices[i]) {
      return i;
    }
  }

  throw out_of_range("没有这个顶点！");
}

/* 判断无向图是否是树 */
bool is_tree(vector<Vertex *> &adjList, vector<int> &vertices) {
  int n = vertices.size(); // 顶点数量

  // 条件一：检查边数是否满足 e=n-1
  int e = 0;
  for (auto vertex : adjList) {
    Vertex *tmp = vertex->next;
    while (tmp) {
      e++;
      tmp = tmp->next;
    }
  }
  // 无向图的边数量
  e = e / 2;
  if (e != n - 1) {
    return false;
  }

  // 条件二：检出图是否是连通的
  vector<bool> visited(n, false);

  // dfs 辅助函数（lambda 函数）
  function<void(int)> dfs = [&](int index) {
    visited[index] = true;
    Vertex *next_vertex = adjList[index]->next;
    while (next_vertex) {
      int next_index = get_index(next_vertex->val, vertices);
      // 如果没有访问过
      if (!visited[next_index]) {
        dfs(next_index);
      }
      next_vertex = next_vertex->next;
    }
  };

  dfs(0);

  // 如果出现还要未访问的节点，说明图不是连通的
  for (bool val : visited) {
    if (!val) {
      return false;
    }
  }

  return true;
}

void test() {
  vector<int> vertices = {1, 3, 2, 5, 4};
  vector<vector<int>> edges = {
      {1, 3},
      {1, 5},
      {3, 2},
      {2, 5},
      {2, 4},
      {4, 5}};

  GraphAdjLinkedList graph(vertices, edges);

  graph.print();

  vector<Vertex *> adjList = graph.get_graph();

  if (is_tree(adjList, vertices)) {
    cout << "是树！" << endl;
  } else {
    cout << "不是树！" << endl;
  }
}

int main() {
  test();

  return 0;
}