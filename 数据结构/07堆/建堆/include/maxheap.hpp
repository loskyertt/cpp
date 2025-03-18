#pragma once

#include <vector>

using namespace std;

class MaxHeap {
  vector<int> max_heap;

  /* 获得当前节点的左孩子 */
  int left(int i);

  /* 获得当前节点的右孩子 */
  int right(int i);

  /* 获得父亲节点 */
  int parent(int i);

  /* 从节点 i 开始，自底至顶堆化 */
  void sift_up(int i);

  /* 从节点 i 开始，自顶至底堆化 */
  void sift_down(int i);

public:
  /* 获取堆大小 */
  int size();

  /* 访问堆顶元素 */
  int top();

  /* 元素入堆 */
  void push(int val);

  /* 元素出堆 */
  void pop();

  /* 判断堆是否为空 */
  bool is_empty();
};