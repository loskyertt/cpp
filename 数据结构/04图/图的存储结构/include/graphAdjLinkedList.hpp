#pragma once

#include <vector>
using namespace std;

/* 顶点 */
struct Vertex {
  int val;
  Vertex *next;
  Vertex(int x) : val(x), next(nullptr) {}
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

  /* 获取目标元素索引 */
  int get_index(int target);

  /* 打印链表 */
  void print_linkedlist(Vertex *node);

public:
  /* 构造方法 */
  GraphAdjLinkedList(const vector<int> vertices, const vector<vector<int>> &edges);

  /* 析构函数，释放申请的内存 */
  ~GraphAdjLinkedList();

  /* 获取顶点数量 */
  int size();

  /* 添加边 */
  void add_edge(int src, int dist);

  /* 删除边 */
  void remove_edge(int src, int dist);

  /* 添加顶点 */
  void add_vertex(int vertex);

  /* 删除顶点 */
  void remove_vertex(int vertex);

  /* 打印邻接表 */
  void print();
};