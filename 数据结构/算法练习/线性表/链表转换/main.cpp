/* 快慢指针，用于找链表中的中间节点 */
#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 找中间节点 */
ListNode *find_middle(ListNode *head) {
  ListNode *slow = head, *fast = head;
  // 这是标准的快慢指针写法。适用于链表长度为偶数或奇数的情况
  // 不能写成 while (fast) 或 while (fast->next)
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }

  return slow;
}

/* 反转后半部分链表 */
ListNode *reverse_list(ListNode *head) {

  ListNode *prev = nullptr;
  ListNode *curr = head;
  while (curr) {
    ListNode *nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev;
}

/* 合并两个链表 */
void merge_lists(ListNode *first, ListNode *second) {
  while (second) {
    ListNode *tmp1 = first->next;
    ListNode *tmp2 = second->next;

    first->next = second;
    second->next = tmp1;
    first = tmp1;
    second = tmp2;
  }
}

/* 打印链表 */
void print_list(ListNode *head) {

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;
}

void rearrange_list(ListNode *head) {
  if (!head || !head->next)
    return;

  // 步骤1：找到链表的中点
  ListNode *middle = find_middle(head);

  // 步骤2：反转链表的后半部分
  ListNode *secondHalf = reverse_list(middle->next);
  middle->next = nullptr; // 断开前半部分和后半部分

  // 步骤3：交替合并两部分链表
  merge_lists(head, secondHalf);
}

int main() {
  // 创建一个链表：1 -> 2 -> 3 -> 4 -> 5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  cout << "初始链表：" << endl;
  print_list(head);

  cout << endl;

  cout << "后半部分链表：" << endl;
  print_list(find_middle(head));

  cout << endl;

  rearrange_list(head);

  cout << "重新排列链表：";
  print_list(head);

  return 0;
}