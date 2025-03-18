#include "maxheap.hpp"
#include <stdexcept>
#include <utility>

// private:
/* 获得当前节点的左孩子 */
int MaxHeap::left(int i) {
  return 2 * i + 1;
}

/* 获得当前节点的右孩子 */
int MaxHeap::right(int i) {
  return 2 * i + 2;
}

/* 获得父亲节点 */
int MaxHeap::parent(int i) {
  return (i - 1) / 2;
}

/* 从节点 i 开始，自底至顶堆化 */
void MaxHeap::sift_up(int i) {
  while (true) {
    // 获取节点 i 的父节点
    int parent_index = parent(i);
    // 当“越过根节点”或“节点无需修复”时，结束堆化
    if (parent_index < 0 || max_heap[i] <= max_heap[parent_index]) {
      break;
    }
    // 交换俩节点
    swap(max_heap[parent_index], max_heap[i]);
    i = parent_index;
  }
}

/* 从节点 i 开始，自顶至底堆化 */
void MaxHeap::sift_down(int i) {

  while (true) {
    int left_index = left(i);   // 当前节点的左孩子
    int right_index = right(i); // 当前节点的右孩子
    int max_index = i;          // 最大节点索引

    if (left_index < size() && max_heap[left_index] > max_heap[max_index]) {
      max_index = left_index;
    }
    if (right_index < size() && max_heap[right_index] > max_heap[max_index]) {
      max_index = right_index;
    }
    // 若节点 i 最大或索引 left_index, right_index 越界，则无须继续堆化，跳出
    if (max_index == i) {
      break;
    }

    swap(max_heap[i], max_heap[max_index]);
    i = max_index;
  }
}

// public:
/* 获取堆大小 */
int MaxHeap::size() {
  return max_heap.size();
}

/* 访问堆顶元素 */
int MaxHeap::top() {
  if (is_empty()) {
    throw out_of_range("堆为空！");
  }

  return max_heap[0];
}

/* 元素入堆 */
void MaxHeap::push(int val) {
  max_heap.push_back(val);

  sift_up(size() - 1);
}

/* 元素出堆 */
void MaxHeap::pop() {
  if (is_empty()) {
    throw out_of_range("堆为空！");
  }

  // 将堆顶元素和最后一个元素交换
  swap(max_heap[0], max_heap[size() - 1]);

  // 弹出最后一个元素
  max_heap.pop_back();

  sift_down(0);
}

/* 判断堆是否为空 */
bool MaxHeap::is_empty() {
  return max_heap.empty();
}