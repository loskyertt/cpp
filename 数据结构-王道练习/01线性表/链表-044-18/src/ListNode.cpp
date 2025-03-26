#include "ListNode.hpp"
#include <iostream>

/* 打印链表 */
void print_list(ListNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->letter << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

/* 获取单链表长度 */
int get_ListNode_length(ListNode *head) {
  int length = 0;
  head = head->next;
  while (head) {
    length++;
    head = head->next;
  }

  return length;
}

/* 字符串转链表 */
ListNode *word_to_ListNode(string word) {
  if (word.length() == 0) {
    cout << "输入的单词不能为空！" << endl;
  }

  ListNode *head = new ListNode('H');
  ListNode *curr = head;
  for (int i = 0; i < word.length(); i++) {
    curr->next = new ListNode(word[i]);
    curr = curr->next;
  }

  return head;
}