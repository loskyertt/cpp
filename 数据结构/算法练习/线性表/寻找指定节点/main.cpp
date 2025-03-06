#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 打印链表 */
void print_ListNode(ListNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

/* 获得链表长度 */
int get_ListNode_length(ListNode *head) {
  int length = 0;
  head = head->next;
  while (head) {
    length++;
    head = head->next;
  }

  return length;
}

/* 方案一：获取倒数第 k 个节点 */
int get_Node(ListNode *head, int k) {
  int length = get_ListNode_length(head);
  cout << "length = " << length << endl;
  head = head->next; // 把头节点去掉
  if (k > length || k <= 0) {
    cout << "没有这个节点！" << endl;
    return 0;
  }

  int index = length - k;
  cout << "index = " << index << endl;

  for (int i = 0; i < index; i++) {
    head = head->next;
  }

  cout << "倒数第 " << k << " 节点值为：" << head->val << endl;

  return 1;
}

/* 方案二：获取倒数第 k 个节点，使用快慢指针 */
int get_K_back_Node(ListNode *head, int k) {
  if (head == nullptr || k <= 0) {
    cout << "没有这个节点" << endl;
  }

  ListNode *slow = head, *fast = head;

  // fast指针先走k步
  for (int i = 0; i < k; i++) {
    fast = fast->next;
  }

  // fast和slow指针同时走
  while (fast) {
    fast = fast->next;
    slow = slow->next;
  }

  cout << "倒数第 " << k << " 节点值为：" << slow->val << endl;

  return 1;
}

void test() {
  ListNode *head = new ListNode(0); // 头节点，无意义
  head->next = new ListNode(1);
  head->next->next = new ListNode(4);
  head->next->next->next = new ListNode(7);
  head->next->next->next->next = new ListNode(3);
  head->next->next->next->next->next = new ListNode(2);
  head->next->next->next->next->next->next = new ListNode(6);

  print_ListNode(head->next);

  get_Node(head, 4);
  get_K_back_Node(head, 4);
}

int main() {
  test();

  return 0;
}