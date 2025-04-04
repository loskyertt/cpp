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

/* 去除重复节点，链表递增有序，按照前面顺序表去重的思路 */
void remove_duplicate(ListNode *head) {
  ListNode *slow = head->next, *fast = slow->next;
  while (fast) {
    if (slow->val != fast->val) {
      slow = slow->next;
      slow->val = fast->val;
    }

    fast = fast->next;
  }

  // 删除 slow 后面的节点，因为 slow 指向的就是去重后的链表的最后一个节点
  while (slow->next) {
    ListNode *tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;
  }
}

// 去除重复节点，链表递增有序
void test_01() {
  vector<int> nums = {7, 10, 21, 30, 42, 42, 42, 70, 70};
  ListNode *head = convert_linked_list(nums);

  cout << "初始链表：";
  print_linked_list(head);

  cout << "去重后的链表：";
  remove_duplicate(head);
  print_linked_list(head);

  free_linked_list(head);
}

int main() {

  test_01();

  return 0;
}