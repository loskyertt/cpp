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

/* 拆分链表 */
ListNode *split_linked_list(ListNode *head) {
  ListNode *b = new ListNode(INT_MAX);
  ListNode *curr = head->next;
  // 如果 curr->next 为 nullptr，说明 curr 没有下一个节点，也就说明 b 链表处理完了
  while (curr && curr->next) {
    ListNode *temp = curr->next;
    curr->next = temp->next;
    curr = curr->next;
    // 通过头插法插入节点，就能实现逆序链表
    temp->next = b->next;
    b->next = temp;
  }

  return b;
}

void test_01() {
  vector<int> nums = {2, 3, 7, 8, 10, 1, 4, 6, 9, 5};
  ListNode *head = convert_linked_list(nums);
  cout << "初始链表为：";
  print_linked_list(head);

  ListNode *b = split_linked_list(head);
  cout << "a 链表：";
  print_linked_list(head);
  cout << "b 链表：";
  print_linked_list(b);

  // 释放内存
  free_linked_list(head);
  free_linked_list(b);
}

int main() {
  test_01();

  return 0;
}