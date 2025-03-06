#include "ListNode.hpp"
#include "stack/stack.hpp"
#include <stdexcept>

/* ----------------------数组实现------------------------------- */
/* 入栈 */
void ArrayStack::push(int val) {
  stack.push_back(val);
}

/* 访问栈顶元素 */
int ArrayStack::top() {
  if (empty()) {
    throw out_of_range("栈为空！");
  }
  return stack.back();
}

/* 元素出栈 */
void ArrayStack::pop() {
  if (empty()) {
    throw out_of_range("栈为空！");
  }
  stack.pop_back();
}

/* 获取栈的长度 */
int ArrayStack::size() {
  return stack.size();
}

/* 判断是否为空 */
bool ArrayStack::empty() {
  return size() == 0;
}

/* ----------------------链表实现------------------------------- */
LinkedListStack::LinkedListStack() {
  stackTop = nullptr;
  stackSize = 0;
}

LinkedListStack::~LinkedListStack() {
  // 遍历链表删除节点，释放内存
  while (stackTop) {
    ListNode *tmp = stackTop;
    stackTop = stackTop->next;
    delete tmp;
  }
}

/* 入栈 */
void LinkedListStack::push(int val) {
  ListNode *newNode = new ListNode(val);
  newNode->next = stackTop;
  stackTop = newNode;
  stackSize++;
}

/* 访问栈顶元素 */
int LinkedListStack::top() {
  if (empty()) {
    throw out_of_range("栈为空");
  }
  return stackTop->val;
}

/* 元素出栈 */
void LinkedListStack::pop() {
  if (empty()) {
    throw out_of_range("栈为空");
  }
  ListNode *tmp = stackTop;
  stackTop = stackTop->next;
  delete tmp;
  stackSize--;
}

/* 获取栈的长度 */
int LinkedListStack::size() {
  return stackSize;
}

/* 判断是否为空 */
bool LinkedListStack::empty() {
  return size() == 0;
}