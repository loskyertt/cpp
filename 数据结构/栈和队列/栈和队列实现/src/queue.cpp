#include "ListNode.hpp"
#include "queue/queue.hpp"
#include <iostream>
#include <stdexcept>

/* ----------------------数组实现------------------------------- */
ArrayQueue::ArrayQueue(int capacity) {
  // 初始化数组
  nums = new int[capacity];
  queueCapacity = capacity;
  front = queueSize = 0;
}

ArrayQueue::~ArrayQueue() {
  delete[] nums;
}

/* 入队 */
void ArrayQueue::push(int x) {
  if (queueSize == queueCapacity) {
    std::cout << "队列已满！" << std::endl;
    return;
  }

  // 计算队尾指针，指向队尾索引 + 1
  // 通过取余操作实现 rear 越过数组尾部后回到头部
  // front + queueSize 表示从队首开始，经过 queueSize 个元素后的位置（相当于到了 rear 位置）
  // 取余操作可以确保 rear 指针始终在数组的有效范围内（0 到 queueCapacity - 1），避免数组越界访问
  int rear = (front + queueSize) % queueCapacity; // 等价于 (rear + 1) % queueCapacity,前提是要维护一个 rear 指针
  // 将 num 添加至队尾
  nums[rear] = x;
  queueSize++;
}

/* 访问队首元素 */
int ArrayQueue::peek() {
  if (empty()) {
    throw std::out_of_range("队列为空");
  }
  return nums[front];
}

/* 出队 */
void ArrayQueue::pop() {
  front = (front + 1) % queueCapacity;
  queueSize--;
}

/* 获取队列长度 */
int ArrayQueue::size() {
  return queueSize;
}

/* 获取队列容量 */
int ArrayQueue::capacity() {
  return queueCapacity;
}

/* 判断队列是否为空 */
bool ArrayQueue::empty() {
  return size() == 0;
}

/* ----------------------链表实现------------------------------- */
LinkedListQueue::LinkedListQueue() {
  front = rear = nullptr;
  queueSize = 0;
}

LinkedListQueue::~LinkedListQueue() {
  while (front) {
    ListNode *tmp = front;
    front = front->next;
    delete tmp;
  }
  rear = nullptr;
}

/* 入队 */
void LinkedListQueue::push(int x) {
  ListNode *newNode = new ListNode(x);
  if (front == nullptr) {
    front = rear = newNode;
  } else {
    rear->next = newNode;
    rear = rear->next;
  }

  queueSize++;
}

/* 访问队首元素 */
int LinkedListQueue::peek() {
  if (empty()) {
    throw std::out_of_range("队列为空");
  }

  return front->val;
}

/* 出队 */
void LinkedListQueue::pop() {
  if (empty()) {
    throw std::out_of_range("队列为空");
  }

  ListNode *tmp = front;
  front = front->next;
  delete tmp;

  queueSize--;
}

/* 获取队列长度 */
int LinkedListQueue::size() {
  return queueSize;
}

/* 判断队列是否为空 */
bool LinkedListQueue::empty() {
  return front == nullptr;
}