#pragma once

#include "ListNode.hpp"
#include <vector>

using namespace std;

class ArrayStack {

  vector<int> stack;

public:
  /* 入栈 */
  void push(int val);

  /* 访问栈顶元素 */
  int top();

  /* 元素出栈 */
  void pop();

  /* 获取栈的长度 */
  int size();

  /* 判断是否为空 */
  bool empty();
};

class LinkedListStack {

  ListNode *stackTop; // 将头节点作为栈顶
  int stackSize;      // 栈的长度

public:
  LinkedListStack();

  ~LinkedListStack();
  /* 入栈 */
  void push(int val);

  /* 访问栈顶元素 */
  int top();

  /* 元素出栈 */
  void pop();

  /* 获取栈的长度 */
  int size();

  /* 判断是否为空 */
  bool empty();
};