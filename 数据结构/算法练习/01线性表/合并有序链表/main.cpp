#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 通过列表创建链表 */
void create_linklist(ListNode *head, vector<int> nums) {
  for (int num : nums) {
    head->next = new ListNode(num);
    head = head->next;
  }
}

/* 打印链表 */
void print_list(ListNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }

  cout << "nullptr" << endl;
}

/* 将两个升序链表合并为一个升序链表，新链表无重复数据，枚举法实现 */
ListNode *merge_linklist_enumerate(ListNode *head1, ListNode *head2) {
  ListNode *head3 = new ListNode(INT_MAX);

  ListNode *curr1 = head1->next;
  ListNode *curr2 = head2->next;
  ListNode *curr3 = head3;

  while (curr1 != nullptr && curr2 != nullptr) {
    if (curr1->val == curr2->val) {
      ListNode *newNode = new ListNode(curr1->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr1 和 curr2 都移到下一个节点
      curr1 = curr1->next;
      curr2 = curr2->next;
    } else if (curr1->val < curr2->val) {
      ListNode *newNode = new ListNode(curr1->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr1 移到下一个节点
      curr1 = curr1->next;
    }

    else {
      ListNode *newNode = new ListNode(curr2->val);
      curr3->next = newNode;
      curr3 = curr3->next;
      // curr2 移到下一个节点
      curr2 = curr2->next;
    }
  }

  // 连接剩余部分的节点
  while (curr1 != nullptr) {
    ListNode *newNode = new ListNode(curr1->val);
    curr3->next = newNode;
    curr3 = curr3->next;
    curr1 = curr1->next;
  }

  while (curr2 != nullptr) {
    ListNode *newNode = new ListNode(curr2->val);
    curr3->next = newNode;
    curr3 = curr3->next;
    curr2 = curr2->next;
  }

  return head3;
}

void test() {
  vector<int> nums1 = {1, 3, 4, 5, 9, 10, 11};
  vector<int> nums2 = {1, 2, 3, 6, 8, 12};

  ListNode *head1 = new ListNode(INT_MAX);
  ListNode *head2 = new ListNode(INT_MAX);

  create_linklist(head1, nums1);
  create_linklist(head2, nums2);

  cout << "head1: ";
  print_list(head1->next);
  cout << "head2: ";
  print_list(head2->next);

  ListNode *head3 = merge_linklist_enumerate(head1, head2);
  cout << "枚举法实现：head3: ";
  print_list(head3->next);
}

int main() {
  test();

  return 0;
}