#include <climits>
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

/* 删除链表中值最小的节点 */
void remove_min_node(ListNode *head) {
  int min_val = INT_MAX;
  ListNode *prev = head, *curr = head->next;
  ListNode *temp_prev = nullptr, *temp_curr = nullptr;

  while (curr) {
    if (curr->val < min_val) {
      min_val = curr->val;
      // 记录最小值对应的节点和它的前驱节点
      temp_curr = curr;
      temp_prev = prev;
    }

    prev = curr;
    curr = curr->next;
  }

  temp_prev->next = temp_curr->next;
  delete temp_curr;
}

void test_01() {
  vector<int> nums = {2, 3, 7, 8, 10, 1, 4, 6};
  ListNode *head = convert_linked_list(nums);
  cout << "初始链表为：";
  print_linked_list(head);

  cout << "删除最小值后的链表：";
  remove_min_node(head);
  print_linked_list(head);

  free_linked_list(head);
}

int main() {
  test_01();

  return 0;
}