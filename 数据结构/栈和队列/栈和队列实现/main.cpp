#include "queue/queue.hpp"
#include "stack/stack.hpp"
#include <iostream>
#include <queue>
#include <stack>

/* 测试标准库里的栈 */
void test_stack() {
  stack<int> stack;
  /* 元素入栈 */
  stack.push(1);
  stack.push(2);
  stack.push(4);

  /* 访问栈顶元素 */
  int top = stack.top();
  cout << "top = " << top << endl;

  /* 元素出栈 */
  stack.pop();
  cout << "top = " << stack.top() << endl;

  /* 获取栈长度 */
  int size = stack.size();
  cout << "Stack size: " << size << endl;

  /* 判断是否为空 */
  if (stack.empty()) {
    cout << "栈为空！" << endl;
  } else {
    cout << "栈中还有元素" << endl;
  }
}

/* 测试数组实现的栈 */
void test_ArrayStack() {
  ArrayStack stack;

  /* 元素入栈 */
  stack.push(1);
  stack.push(2);
  stack.push(4);

  /* 访问栈顶元素 */
  int top = stack.top();
  cout << "top = " << top << endl;

  /* 元素出栈 */
  stack.pop();
  cout << "top = " << stack.top() << endl;

  /* 获取栈长度 */
  int size = stack.size();
  cout << "Stack size: " << size << endl;

  /* 判断是否为空 */
  if (stack.empty()) {
    cout << "栈为空！" << endl;
  } else {
    cout << "栈中还有元素" << endl;
  }
}

/* 测试链表实现的栈 */
void test_LinkedListStack() {
  LinkedListStack stack;

  /* 元素入栈 */
  stack.push(1);
  stack.push(2);
  stack.push(4);

  /* 访问栈顶元素 */
  int top = stack.top();
  cout << "top = " << top << endl;

  /* 元素出栈 */
  stack.pop();
  cout << "top = " << stack.top() << endl;

  /* 获取栈长度 */
  int size = stack.size();
  cout << "Stack size: " << size << endl;

  /* 判断是否为空 */
  if (stack.empty()) {
    cout << "栈为空！" << endl;
  } else {
    cout << "栈中还有元素" << endl;
  }
}

/* 测试标准库里的队列 */
void test_queue() {
  queue<int> queue;

  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  // 获取队首值
  cout << "front = " << queue.front() << endl;

  // 删除队首值
  queue.pop();

  // 获取队列长度
  int size = queue.size();
  cout << "size = " << size << endl;

  /* 判断是否为空 */
  if (queue.empty()) {
    cout << "队列为空！" << endl;
  } else {
    cout << "队列中还有元素" << endl;
  }
}

/* 测试数组实现的环形队列 */
void test_ArrayQueue() {
  ArrayQueue queue(5);
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);

  // 获取队首值
  cout << "front = " << queue.peek() << endl;

  // 删除队首值
  queue.pop();

  // 获取队列长度
  int size = queue.size();
  cout << "size = " << size << endl;

  /* 判断是否为空 */
  if (queue.empty()) {
    cout << "队列为空！" << endl;
  } else {
    cout << "队列中还有元素" << endl;
  }
}

int main() {
  // test_stack();
  // test_ArrayStack();
  // test_LinkedListStack();

  test_queue();
  // test_ArrayQueue();

  return 0;
}