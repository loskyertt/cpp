#include "dijkstra.hpp"
#include "floyd.hpp"
#include "graphAdjMat.hpp"

#include <climits>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void test_GraphAdjMat() {
  vector<char> vertices = {'a', 'b', 'c', 'd', 'e', 'f'};
  vector<vector<int>> edges = {// {v1(index), v2(index), weight}
                               {0, 1, 2},
                               {0, 2, 5},
                               {1, 2, 1},
                               {1, 3, 3},
                               {2, 3, 3},
                               {2, 4, 4},
                               {2, 5, 1},
                               {3, 4, 1},
                               {3, 5, 4},
                               {4, 5, 1}};

  GraphAdjMat graph(vertices, edges);
  graph.print();

  cout << endl;

  vector<vector<int>> adjMat = graph.get_adjMat();

  vector<int> dist = dijkstra(0, vertices, adjMat);
  cout << "Dijkstra（优先队列实现）：" << endl;
  for (size_t i = 0; i < dist.size(); i++) {
    cout << vertices[i] << " -> " << (dist[i] == INT_MAX ? "∞" : to_string(dist[i])) << endl;
  }

  cout << endl;

  cout << "Dijkstra（数组实现）：" << endl;
  PathInfo path_info = dijkstra(0, adjMat);

  for (int i = 0; i < adjMat.size(); i++) {

    stack<int> stk; // 因为是倒着往回推的，为了保证顺序，需要用栈来反转下
    int cur = i;    // 不能修改 i，使用 cur 代替
    while (path_info.path[cur] != -1) {
      stk.push(path_info.path[cur]);
      cur = path_info.path[cur]; // 这里用 cur 记录当前顶点的前驱顶点
    }

    cout << vertices[i] << "(distance = " << path_info.distance[i] << ")" << "：";
    while (!stk.empty()) {
      cout << vertices[stk.top()] << " -> ";
      stk.pop();
    }
    cout << vertices[i] << endl; // 最后输出终点
  }

  cout << endl;

  cout << "Floyd:" << endl;
  vector<vector<int>> distance = floyd(adjMat);

  for (auto row : distance) {
    for (auto val : row) {
      if (val == INT_MAX) {
        cout << "∞ ";
      } else {
        cout << val << " ";
      }
    }
    cout << endl;
  }
}

int main() {

  test_GraphAdjMat();

  return 0;
}