#include <cstddef>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 在链表的节点 n0 之后插入节点 P */
void insert(ListNode *n0, ListNode *P) {
  ListNode *n1 = n0->next;
  P->next = n1;
  n0->next = P;
}

/* 删除链表的节点 n0 之后的首个节点 */
void remove(ListNode *n0) {
  if (n0->next == nullptr)
    return;
  // n0 -> P -> n1
  ListNode *P = n0->next;
  ListNode *n1 = P->next;
  n0->next = n1;
  // 释放内存
  delete P;
}

/*
调用print_list(n0)时，传递的是n0的副本，即函数参数head接收的是n0的值，也就是链表的头节点地址。
在print_list函数内部，循环中的head = head->next确实改变了函数内的局部变量head，但这不会影响main函数中的n0指针，因为函数参数是按值传递的。
所以，当print_list执行完毕后，main中的n0仍然指向原来的头节点，并没有被修改。
*/
void print_list(const ListNode *head) {
  if (head == NULL) {
    cout << "链表为空！" << endl;
  }
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }

  cout << endl;
}

void test_list() {
  /* 初始化链表 1 -> 3 -> 2 -> 5 -> 4 */
  // 初始化各个节点
  ListNode *n0 = new ListNode(1);
  ListNode *n1 = new ListNode(3);
  ListNode *n2 = new ListNode(2);
  ListNode *n3 = new ListNode(5);
  ListNode *n4 = new ListNode(4);
  // 构建节点之间的引用
  n0->next = n1;
  n1->next = n2;
  n2->next = n3;
  n3->next = n4;

  // 初始链表
  cout << "初始链表：" << endl;
  print_list(n0);

  cout << "增加新节点后的链表：" << endl;
  ListNode *newNode = new ListNode(7);
  // 思考：为什么在`insert`函数中修改指针副本的`next`成员却能影响到主函数中的链表结构？
  /*
  这里的关键在于，虽然指针本身是副本，但它们指向的是同一块内存地址。
  举个例子，假设主函数中的`n1`指向地址0x1000，那么在调用`insert(n1, newNode)`时，函数参数`n0`是`n1`的一个副本，也指向0x1000。当执行`n0->next = P;`时，实际上是在修改地址0x1000处的节点的`next`成员。主函数中的`n1`仍然指向0x1000，而这个节点的`next`已经被修改了，所以主函数中的链表结构也随之改变。
  */
  insert(n1, newNode);
  print_list(n0);

  cout << "删除节点后的链表：" << endl;
  remove(n2);
  print_list(n0);
}

int main() {

  test_list();

  return 0;
}