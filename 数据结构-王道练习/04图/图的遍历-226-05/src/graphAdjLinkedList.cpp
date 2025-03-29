#include "graphAdjLinkedList.hpp"
#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <tuple>
#include <vector>

// private:
/* 添加节点：把 n1 节点添加到 n0 链表后 */
void GraphAdjLinkedList::add_node(Vertex *n0, Vertex *n1) {
  // 添加到 n0 链表的末尾
  // while (n0->next != nullptr) {
  //   n0 = n0->next;
  // }
  // n0->next = n1;

  // 添加到 n0 节点的下一个节点
  if (n0->next == nullptr) {
    n0->next = n1;
  } else {
    Vertex *tmp = n0->next;
    n0->next = n1;
    n1->next = tmp;
  }
}

/* 删除节点：把值为 val 的节点从 n0 节点后删除*/
void GraphAdjLinkedList::remove_node(Vertex *n0, int val) {
  Vertex *prev = n0;
  Vertex *curr = n0->next;
  while (curr) {
    if (curr->val == val) {
      Vertex *tmp = curr;
      curr = curr->next;
      prev->next = curr;
      delete tmp;
      break;
    }

    prev = curr;
    curr = curr->next;
  }
}

/* 获取目标元素索引 */
int GraphAdjLinkedList::get_index(int target) {
  for (int i = 0; i < vertices.size(); i++) {
    if (vertices[i] == target) {
      return i;
    }
  }

  throw out_of_range("没有这个顶点！");
  // return -1;
}

/* 打印链表 */
void GraphAdjLinkedList::print_linkedlist(Vertex *node) {
  cout << "[ ";
  while (node) {
    cout << node->val << " -> ";
    node = node->next;
  }
  cout << "nullptr" << " ]" << endl;
}

// public:
/* 构造方法 */
GraphAdjLinkedList::GraphAdjLinkedList(const vector<int> vertices,
                                       const vector<vector<int>> &edges) {
  for (int vertex : vertices) {
    add_vertex(vertex);
  }

  for (auto edge : edges) {
    add_edge(edge[0], edge[1]);
  }
}

/* 获取顶点数量 */
int GraphAdjLinkedList::size() {
  return vertices.size();
}

/* 添加边 */
void GraphAdjLinkedList::add_edge(int src, int dist) {
  if (find(vertices.begin(), vertices.end(), src) == vertices.end() ||
      find(vertices.begin(), vertices.end(), dist) == vertices.end()) {
    throw out_of_range("没有这些顶点！");
  }

  Vertex *vet_src = new Vertex(src);
  Vertex *vet_dist = new Vertex(dist);

  for (auto vet : adjList) {
    if (vet->val == src) {
      add_node(vet, vet_dist);
    }
    if (vet->val == dist) {
      add_node(vet, vet_src);
    }
  }
}

/* 删除边 */
void GraphAdjLinkedList::remove_edge(int src, int dist) {
  if (find(vertices.begin(), vertices.end(), src) == vertices.end() ||
      find(vertices.begin(), vertices.end(), dist) == vertices.end()) {
    throw out_of_range("无效的边！");
  }

  for (auto vet : adjList) {
    if (vet->val == src) {
      remove_node(vet, dist);
    }
    if (vet->val == dist) {
      remove_node(vet, src);
    }
  }
}

/* 添加顶点 */
void GraphAdjLinkedList::add_vertex(int vertex) {
  vertices.push_back(vertex);
  Vertex *new_vertex = new Vertex(vertex);
  adjList.push_back(new_vertex);
}

/* 删除顶点 */
void GraphAdjLinkedList::remove_vertex(int vertex) {
  int index = get_index(vertex);

  // 先删除每条边
  for (int val : vertices) {
    remove_edge(val, vertex);
  }

  // 把顶点从顶点列表中移除
  vertices.erase(vertices.begin() + index);

  // 删除链表所有节点
  Vertex *curr = adjList[index];
  while (curr) {
    Vertex *tmp = curr;
    curr = curr->next;
    delete tmp;
  }
  adjList.erase(adjList.begin() + index);
}

/* 打印邻接表 */
void GraphAdjLinkedList::print() {
  cout << "邻接表（链表实现）：" << endl;
  for (const auto adj : adjList) {
    cout << adj->val << " -> ";
    print_linkedlist(adj->next);
  }
  cout << endl;
}

/* 求 Vi 到 Vj 的所有简单路径：bfs */
vector<vector<int>> GraphAdjLinkedList::get_paths_bfs(int begin, int end) {
  vector<vector<int>> paths;

  // 如果起点和终点相同
  if (begin == end) {
    paths.push_back({begin});
    return paths;
  }

  int begin_index = get_index(begin);
  int end_index = get_index(end);

  // 队列中存储<当前节点索引, 当前路径, 已访问节点集合>
  queue<tuple<int, vector<int>, vector<bool>>> q;
  vector<bool> initial_visited(size(), false);
  initial_visited[begin_index] = true;

  // 初始路径只包含起点
  q.push(make_tuple(begin_index, vector<int>{begin}, initial_visited));

  while (!q.empty()) {
    auto [curr_index, curr_path, curr_visited] = q.front();
    q.pop();

    // 遍历当前节点的所有邻接点
    Vertex *next_vertex = adjList[curr_index]->next;
    while (next_vertex) {
      int next_index = get_index(next_vertex->val);
      int next_val = next_vertex->val;

      // 如果找到终点
      if (next_index == end_index) {
        vector<int> complete_path = curr_path;
        complete_path.push_back(end);
        paths.push_back(complete_path);
      }
      // 如果节点未访问过，加入新路径继续搜索
      else if (!curr_visited[next_index]) {
        vector<bool> new_visited = curr_visited;
        new_visited[next_index] = true;

        vector<int> new_path = curr_path;
        new_path.push_back(next_val);

        q.push(make_tuple(next_index, new_path, new_visited));
      }

      next_vertex = next_vertex->next;
    }
  }

  return paths;
}

/* 求 Vi 到 Vj 的所有简单路径：dfs */
vector<vector<int>> GraphAdjLinkedList::get_paths_dfs(int begin, int end) {
  vector<vector<int>> paths;           // 存储所有找到的路径
  vector<int> current_path;            // 当前探索的路径
  vector<bool> visited(size(), false); // 访问标记

  // 如果起点和终点相同
  if (begin == end) {
    paths.push_back({begin});
    return paths;
  }

  // 定义 DFS 辅助函数
  function<void(int, int)> dfs = [&](int current, int target) {
    int current_index = get_index(current);

    // 标记当前节点为已访问
    visited[current_index] = true;
    current_path.push_back(current);

    // 如果到达目标节点
    if (current == target) {
      paths.push_back(current_path); // 添加完整路径到结果集
    } else {
      // 继续搜索邻接节点
      Vertex *next_vertex = adjList[current_index]->next;
      while (next_vertex) {
        int next_val = next_vertex->val;
        int next_index = get_index(next_val);

        // 如果邻接节点未访问过
        if (!visited[next_index]) {
          dfs(next_val, target);
        }

        next_vertex = next_vertex->next;
      }
    }

    // 回溯：移除当前节点，取消访问标记
    current_path.pop_back();
    visited[current_index] = false;
  };

  // 从起点开始 DFS
  dfs(begin, end);

  return paths;
}