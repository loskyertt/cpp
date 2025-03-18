#include "maxheap.hpp"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void test_priority_queue() {
  // 初始化小顶堆
  priority_queue<int, vector<int>, greater<int>> min_heap;

  min_heap.push(1);
  min_heap.push(3);
  min_heap.push(2);
  min_heap.push(5);
  min_heap.push(4);

  cout << "小顶堆：";
  while (!min_heap.empty()) {
    cout << min_heap.top() << " ";
    min_heap.pop();
  }
  cout << endl;

  // 初始化大顶堆
  priority_queue<int, vector<int>, less<int>> max_heap;
  max_heap.push(1);
  max_heap.push(3);
  max_heap.push(2);
  max_heap.push(5);
  max_heap.push(4);

  cout << "大顶堆：";
  while (!max_heap.empty()) {
    cout << max_heap.top() << " ";
    max_heap.pop();
  }
  cout << endl;
}

void test_my_max_heap() {
  MaxHeap max_heap;
  max_heap.push(1);
  max_heap.push(3);
  max_heap.push(2);
  max_heap.push(5);
  max_heap.push(4);

  cout << "大顶堆：";
  while (!max_heap.is_empty()) {
    cout << max_heap.top() << " ";
    max_heap.pop();
  }
  cout << endl;
}

int main() {
  // test_priority_queue();
  test_my_max_heap();

  return 0;
}