#pragma once

#include <string>

using namespace std;

struct ListNode {
  char letter;
  ListNode *next;
  ListNode(char x) : letter(x), next(nullptr) {}
};

/* 打印链表 */
void print_list(ListNode *head);

/* 获取单链表长度 */
int get_ListNode_length(ListNode *head);

/* 字符串转链表 */
ListNode *word_to_ListNode(string word);