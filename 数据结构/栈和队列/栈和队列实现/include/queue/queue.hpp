#pragma once

#include "ListNode.hpp"

/* 环形队列 */
class ArrayQueue {

  int *nums;         // 用于存储队列元素的数组
  int front;         // 队首指针，指向队首元素
  int queueSize;     // 队列长度
  int queueCapacity; // 队列容量

public:
  ArrayQueue(int capacity);

  ~ArrayQueue();

  /* 入队 */
  void push(int x);

  /* 访问队首元素 */
  int peek();

  /* 出队 */
  void pop();

  /* 获取队列长度 */
  int size();

  /* 获取队列容量 */
  int capacity();

  /* 判断队列是否为空 */
  bool empty();
};

class LinkedListQueue {
  ListNode *front;
  ListNode *rear;
  int queueSize;

public:
  LinkedListQueue();

  ~LinkedListQueue();

  /* 入队 */
  void push(int x);

  /* 访问队首元素 */
  int peek();

  /* 出队 */
  void pop();

  /* 获取队列长度 */
  int size();

  /* 判断队列是否为空 */
  bool empty();
};