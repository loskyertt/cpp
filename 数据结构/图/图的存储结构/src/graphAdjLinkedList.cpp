#include "graphAdjLinkedList.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>

// private:
/* 添加节点：把 n1 节点添加到 n0 链表后 */
void GraphAdjLinkedList::add_node(Vertex *n0, Vertex *n1) {
  while (n0->link != nullptr) {
    n0 = n0->link;
  }
  n0->link = n1;
}

/* 删除节点：把值为 val 的节点从 n0 节点后删除*/
void GraphAdjLinkedList::remove_node(Vertex *n0, int val) {
  Vertex *prev = n0;
  Vertex *curr = n0->link;
  while (curr) {
    if (curr->val == val) {
      Vertex *tmp = curr;
      curr = curr->link;
      prev->link = curr;
      delete tmp;
      break;
    }

    prev = curr;
    curr = curr->link;
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
void GraphAdjLinkedList::prnt_linkedlist(Vertex *node) {
  cout << "[ ";
  while (node) {
    cout << node->val << " -> ";
    node = node->link;
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
  if (find(vertices.begin(), vertices.end(), src) == vertices.end() || find(vertices.begin(), vertices.end(), dist) == vertices.end()) {
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
  if (find(vertices.begin(), vertices.end(), src) == vertices.end() || find(vertices.begin(), vertices.end(), dist) == vertices.end()) {
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

  Vertex *curr = adjList[index];
  while (curr) {
    Vertex *tmp = curr;
    curr = curr->link;
    delete tmp;
  }
  adjList.erase(adjList.begin() + index);
}

/* 打印邻接表 */
void GraphAdjLinkedList::print() {
  cout << "邻接表（链表实现）：" << endl;
  for (const auto adj : adjList) {
    cout << adj->val << " -> ";
    prnt_linkedlist(adj->link);
  }
  cout << endl;
}