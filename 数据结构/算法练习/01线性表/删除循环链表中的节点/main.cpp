#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 打印循环链表 */
void print_linklist(ListNode *head) {
  if (!head->next) {
    cout << "链表为空！" << endl;
    return;
  }

  cout << "(" << head->val << ") head" << " -> ";
  ListNode *curr = head->next;
  while (curr != head) {
    cout << curr->val << " -> ";
    curr = curr->next;
  }

  cout << "(" << head->val << ") head" << endl;
}

/* 列表转循环链表 */
ListNode *list_to_loop_linklist(vector<int> list) {
  ListNode *head = new ListNode(INT_MAX);
  ListNode *curr = head;
  for (int val : list) {
    ListNode *newNode = new ListNode(val);
    curr->next = newNode;
    curr = curr->next;
  }
  curr->next = head;

  return head;
}

/* 删除循环链表中 node->val=x 的节点*/
void remove_x(ListNode *head, int x) {
  if (!head->next) {
    cout << "链表为空" << endl;
    return;
  }

  ListNode *curr = head->next;
  ListNode *prev = head;

  while (curr != head) {
    if (curr->val == x) {
      ListNode *tmp = curr;
      curr = curr->next;
      prev->next = curr;
      delete tmp;
    } else {
      curr = curr->next;
      prev = prev->next;
    }
  }
}

void test() {
  vector<int> list = {2, 4, 5, 5, 6, 3, 8};
  ListNode *head = list_to_loop_linklist(list);

  cout << "初始链表：" << endl;
  print_linklist(head);

  remove_x(head, 8);
  cout << "移除 val = x 后的链表：" << endl;
  print_linklist(head);
}

int main() {
  test();

  return 0;
}