#pragma once

#include <vector>

using std::vector;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 通过列表创建链表 */
void create_linklist(ListNode *head, vector<int> nums);

/* 打印链表 */
void print_list(ListNode *head);

/* 将两个升序链表合并为一个升序链表，新链表无重复数据，枚举法实现 */
ListNode *merge_linklist_enumerate(ListNode *head1, ListNode *head2);