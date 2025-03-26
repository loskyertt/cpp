#include "ListNode.hpp"
#include "func_1.hpp"
#include "func_2.hpp"
#include <iostream>

void test_func_1() {
  string word1 = "loading";
  string word2 = "being";

  ListNode *head1 = new ListNode('H');
  ListNode *head2 = new ListNode('H');

  share_suffix(word1, word2, head1, head2);

  cout << "word1: ";
  print_list(head1->next);
  cout << "word2: ";
  print_list(head2->next);
}

void test_func_2() {
  string word1 = "loading";
  string word2 = "being";

  // 先把单词转换为链表
  ListNode *head1 = word_to_ListNode(word1);
  ListNode *head2 = word_to_ListNode(word2);

  // cout << "head1 长度为：" << get_ListNode_length(head1) << endl;

  ListNode *suffix = merge_suffix(head1, head2);
  cout << "后缀起始为：";
  print_list(suffix);
}

int main() {
  // test_func_1();
  test_func_2();

  return 0;
}
