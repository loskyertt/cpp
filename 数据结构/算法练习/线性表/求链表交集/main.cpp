#include <climits>
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

void print_list(ListNode *head) {
  cout << "head -> ";

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }

  cout << "nullptr" << endl;
}

/* 找到链表的交集：使用枚举的方式 */
void get_intersection_enumerate(ListNode *L1, ListNode *L2, ListNode *L3) {
  ListNode *curr1 = L1->next;
  ListNode *tail = L3; // 使用 tail 来构建 L3 链表

  while (curr1) {
    ListNode *curr2 = L2->next; // 重新回到 L2 链表的起点
    while (curr2) {
      if (curr1->val == curr2->val) {
        ListNode *newNode = new ListNode(curr1->val);
        tail->next = newNode;
        tail = newNode;
        break; // 找到交集后跳出内层循环
      }
      curr2 = curr2->next; // 递增 curr2
    }
    curr1 = curr1->next; // 递增 curr1
  }
}

/* 创建空链表 */
ListNode *create_empty_list() {
  return nullptr;
}

void test() {
  ListNode *L1 = new ListNode(INT_MAX);
  L1->next = new ListNode(1);
  L1->next->next = new ListNode(2);
  L1->next->next->next = new ListNode(7);
  L1->next->next->next->next = new ListNode(10);
  L1->next->next->next->next->next = new ListNode(11);

  ListNode *L2 = new ListNode(INT_MAX);
  L2->next = new ListNode(3);
  L2->next->next = new ListNode(2);
  L2->next->next->next = new ListNode(4);
  L2->next->next->next->next = new ListNode(9);
  L2->next->next->next->next->next = new ListNode(11);
  L2->next->next->next->next->next->next = new ListNode(14);

  print_list(L1->next);
  print_list(L2->next);

  ListNode *L3 = new ListNode(INT_MAX);
  get_intersection_enumerate(L1, L2, L3);

  print_list(L3->next);
}

int main() {
  test();

  return 0;
}