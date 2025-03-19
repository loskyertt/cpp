#include "linked_list.hpp"
#include <climits>
#include <iostream>

using std::cout;
using std::endl;

/* 通过列表创建链表 */
void create_linklist(ListNode *head, vector<int> nums) {
  for (int num : nums) {
    head->next = new ListNode(num);
    head = head->next;
  }
}

/* 打印链表 */
void print_list(ListNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }

  cout << "nullptr" << endl;
}

/* 将两个升序链表合并为一个升序链表，新链表无重复数据，枚举法实现 */
ListNode *merge_linklist_enumerate(ListNode *head1, ListNode *head2) {
  ListNode *head3 = new ListNode(INT_MAX);

  ListNode *curr1 = head1->next;
  ListNode *curr2 = head2->next;
  ListNode *curr3 = head3;

  while (curr1 != nullptr && curr2 != nullptr) {
    if (curr1->val == curr2->val) {
      ListNode *newNode = new ListNode(curr1->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr1 和 curr2 都移到下一个节点
      curr1 = curr1->next;
      curr2 = curr2->next;
    } else if (curr1->val < curr2->val) {
      ListNode *newNode = new ListNode(curr1->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr1 移到下一个节点
      curr1 = curr1->next;
    }

    else {
      ListNode *newNode = new ListNode(curr2->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr2 移到下一个节点
      curr2 = curr2->next;
    }
  }

  // 连接剩余部分的节点
  while (curr1 != nullptr) {
    ListNode *newNode = new ListNode(curr1->val);
    curr3->next = newNode;
    curr3 = curr3->next;
    curr1 = curr1->next;
  }

  while (curr2 != nullptr) {
    ListNode *newNode = new ListNode(curr2->val);
    curr3->next = newNode;
    curr3 = curr3->next;
    curr2 = curr2->next;
  }

  return head3;
}