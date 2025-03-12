#pragma once

#include <vector>
using namespace std;

/* 顶点 */
struct Vertex {
  int val;
  Vertex *link;
  Vertex(int x) : val(x), link(nullptr) {}
};

/* 邻接表（链表实现） */
class GraphAdjLinkedList {

  // adjList[i] -> vertex1 -> vertex2 -> ...
  vector<Vertex *> adjList;

  // 顶点列表
  vector<int> vertices;

  /* 添加节点：把 n1 节点添加到 n0 链表后 */
  void add_node(Vertex *n0, Vertex *n1);

  /* 删除节点：把值为 val 的节点从 n0 节点后删除*/
  void remove_node(Vertex *n0, int val);

  /* 打印链表 */
  void prnt_linkedlist(Vertex *node);

public:
  /* 构造方法 */
  GraphAdjLinkedList(const vector<int> vertices, const vector<vector<int>> &edges);

  /* 获取顶点数量 */
  int size();

  /* 添加边 */
  void add_edge(int src, int dist);

  /* 删除边 */
  void remove_edge(int src, int dist);

  /* 添加顶点 */
  void add_vertex(int vertex);

  /* 删除顶点 */
  void remove_vertex(int index);

  /* 打印邻接表 */
  void print();
};