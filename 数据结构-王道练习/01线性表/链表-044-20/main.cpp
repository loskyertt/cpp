#include <climits>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 打印链表 */
void print_linked_list(ListNode *node) {
  cout << "head -> ";
  while (node) {
    cout << node->val << " -> ";
    node = node->next;
  }

  cout << "nullptr" << endl;
}

/* 数组转单链表 */
ListNode *convert_linked_list(vector<int> &nums) {
  // 带头结点
  ListNode *head = new ListNode(INT_MAX);
  ListNode *curr = head;
  for (int num : nums) {
    curr->next = new ListNode(num);
    curr = curr->next;
  }

  return head;
}

/* 释放链表所占内存 */
void free_linked_list(ListNode *node) {
  if (!node) {
    cout << "链表为空！" << endl;
    return;
  }
  while (node) {
    ListNode *temp = node;
    node = node->next;
    delete temp;
  }
}

/* 将链表拆分两半，并返回后半部分的链表。后半部分链表长度 >= 前半部分链表长度 */
ListNode *get_last_linked_list(ListNode *head) {
  ListNode *slow = head->next, *fast = head->next, *prev_s = head;
  // 解决奇数或者偶数长的情况
  while (fast && fast->next) {
    fast = fast->next->next;

    prev_s = slow;
    slow = slow->next;
  }

  prev_s->next = nullptr;

  return slow;
}

/* 逆序链表 */
ListNode *reverse_linked_list(ListNode *head) {
  ListNode *prev = nullptr, *curr = head;
  while (curr) {
    ListNode *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;
  }

  return prev;
}

/* 交错合并两个链表（合并到 head1 中），这里注意传入参数应该是 head-next ，把头节点跳过 */
void merge_linked_lists(ListNode *head1, ListNode *head2) {
  while (head1 && head2) {
    ListNode *temp1 = head1->next;
    head1->next = head2;
    ListNode *temp2 = head2->next;
    if (temp1) {
      head2->next = temp1;
    }

    head1 = temp1;
    head2 = temp2;
  }
}

/* 排列节点 */
void arrange_linked_list(ListNode *head) {
  // 获取后半部分链表
  ListNode *last_half = get_last_linked_list(head);
  // 将后半部分链表逆序
  ListNode *head2 = reverse_linked_list(last_half);
  // 交错合并两个链表
  merge_linked_lists(head->next, head2);
}

// 去除重复节点，链表递增有序
void test_01() {
  vector<int> nums_01 = {1, 2, 3, 4, 5, 6, 7};    // 奇数个序列
  vector<int> nums_02 = {1, 2, 3, 4, 5, 6, 7, 8}; // 偶数个序列
  ListNode *head_01 = convert_linked_list(nums_01);
  ListNode *head_02 = convert_linked_list(nums_02);

  cout << "初始链表（奇数个序列）：";
  print_linked_list(head_01);

  cout << "重新排列后的链表：";
  arrange_linked_list(head_01);
  print_linked_list(head_01);

  cout << endl;

  cout << "初始链表（偶数个序列）：";
  print_linked_list(head_02);

  cout << "重新排列后的链表：";
  arrange_linked_list(head_02);
  print_linked_list(head_02);

  free_linked_list(head_01);
  free_linked_list(head_02);
}

int main() {

  test_01();

  return 0;
}