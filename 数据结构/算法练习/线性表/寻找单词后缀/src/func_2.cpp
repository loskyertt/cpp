#include "ListNode.hpp"
#include "func_2.hpp"
#include <cstdio>

using namespace std;

/* 让相同后缀共享存储 */
ListNode *merge_suffix(ListNode *head1, ListNode *head2) {
  int len1 = get_ListNode_length(head1);
  int len2 = get_ListNode_length(head2);

  // 让较长的链表前进 |len1 - len2| 步
  while (len1 > len2) {
    head1 = head1->next;
    len1--;
  }
  while (len1 < len2) {
    head2 = head2->next;
    len2--;
  }

  // print_list(head1);
  // print_list(head2);

  // 找到公共后缀
  while (head1 && head2 && head1->letter != head2->letter) {
    head1 = head1->next;
    head2 = head2->next;
  }

  return head1; // 返回找到的公共后缀起始节点
}