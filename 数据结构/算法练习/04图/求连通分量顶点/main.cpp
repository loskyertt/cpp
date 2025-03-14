#include "graphAdjLinkedList.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

/* 获取顶点索引 */
int get_index(vector<int> vertices, int val) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i] == val) {
      return i;
    }
  }

  throw out_of_range("没有这个顶点！");
}

/* dfs 遍历邻接表 */
void dfs(int index, vector<bool> &visited, vector<int> vertices, vector<Vertex *> adjList) {
  cout << vertices[index] << " ";
  visited[index] = true;

  Vertex *cur_vertex = adjList[index]->next;
  while (cur_vertex && visited[get_index(vector<int> vertices, int val)]) {
  }
}

void traverse(vector<int> vertices, vector<Vertex *> adjList) {
  int start = 0;
  vector<bool> visited(vertices.size(), false);
  dfs(start, visited, vertices, adjList);
}

void test() {
  vector<int> vertices = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  vector<vector<int>> edges = {{1, 2},
                               {1, 5},
                               {2, 3},
                               {2, 7},
                               {3, 4},
                               {4, 5},
                               {8, 9},
                               {8, 10},
                               {9, 10}};

  GraphAdjLinkedList graph(vertices, edges);

  graph.print();

  vector<Vertex *> adjList = graph.get_adjList();

  traverse(vertices, adjList);
}

int main() {
  test();

  return 0;
}