#include <vector>

using namespace std;

// 边的结构体
struct Edge {
  int to;     // 目标节点
  int weight; // 边的权重
};

struct Node {
  int vertex;   // 节点编号
  int distance; // 当前到达该节点的最短距离

  // 用于优先队列的比较器
  bool operator<(const Node &other) const {
    return distance > other.distance; // 小顶堆
  }
};

// Dijkstra 算法
void dijkstra(int start, const vector<vector<Edge>> &graph);