#include "func_1.hpp"
#include <iostream>

/* 共享存储空间的单词转链表 */
void share_suffix(string word1, string word2, ListNode *head1, ListNode *head2) {
  int i = word1.length(), j = word2.length();

  // 边界检查
  if (i == 0 || j == 0) {
    cout << "输入字符串不能为空！" << endl;
    return;
  }

  // 如果最后一个单词不同，说明没有共同后缀
  if (word1[i - 1] != word2[j - 1]) {
    cout << "无公共后缀！" << endl;
    return;
  }

  // 找到最长公共后缀
  while (i > 0 && j > 0 && word1[i - 1] == word2[j - 1]) {
    i--;
    j--;
  }

  // 定义共同后缀的起始点，比如这里是字母 i 作为后缀其实点
  ListNode *suffix_start = new ListNode(word1[i]);
  // 把后缀转成链表
  ListNode *curr_suffix = suffix_start;
  for (int count = i + 1; count < word1.length(); count++) {
    curr_suffix->next = new ListNode(word1[count]);
    curr_suffix = curr_suffix->next;
  }

  // 构造 word1 的前缀链表
  for (int m = 0; m < i; m++) {
    head1->next = new ListNode(word1[m]);
    head1 = head1->next;
  }
  head1->next = suffix_start;

  // 构造 word2 的前缀链表
  for (int n = 0; n < j; n++) {
    head2->next = new ListNode(word2[n]);
    head2 = head2->next;
  }
  head2->next = suffix_start;
}