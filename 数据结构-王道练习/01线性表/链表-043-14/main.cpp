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
  // 不带头结点
  ListNode *head = new ListNode(nums[0]);
  ListNode *curr = head;
  for (vector<int>::iterator it = nums.begin() + 1; it != nums.end(); it++) {
    ListNode *new_node = new ListNode(*it);
    curr->next = new_node;
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

/* 循环右移链表元素，链表无头节点 */
/* 方式一：快慢指针 */
ListNode *right_shift_k_01(ListNode *node, int k) {
  ListNode *slow = node, *prev_s = nullptr; // 慢指针和记录慢指针指向的节点的前驱节点的指针
  ListNode *fast = node, *prev_f = nullptr; // 快指针和记录快指针指向的节点的前驱节点的指针
  // 先让 fast 指针走 k 步
  while (k) {
    prev_f = fast;
    fast = fast->next;
    k--;
  }

  // 再让快慢指针一起走，当 fast 指针走到空时，slow 指针就走到了倒数第 k 个节点的位置
  while (fast) {
    prev_f = fast;
    fast = fast->next;
    prev_s = slow;
    slow = slow->next;
  }

  // 再重新构造链表
  prev_s->next = nullptr;
  prev_f->next = node;
  return slow;
}

/* 方式二：循环链表 */
ListNode *right_shift_k_02(ListNode *node, int k) {
  ListNode *tail = node;

  // 从 1 开始计数，不然尾指针走到空
  int length = 1;
  while (tail->next) {
    length++;
    tail = tail->next;
  }

  // 连接起始节点构成循环链表
  tail->next = node;

  // 开始找断开的位置
  ListNode *curr = node, *prev = tail;

  int i = length - k;
  while (i) {
    prev = curr;
    curr = curr->next;
    i--;
  }

  prev->next = nullptr;
  return curr;
}

void test_01() {
  cout << "方式一：" << endl;
  vector<int> nums = {0, 1, 2, 3, 4, 7, 8};
  ListNode *node = convert_linked_list(nums);
  cout << "初始链表：";
  print_linked_list(node);

  int k = 3;
  cout << "右移 " << k << " 个单位的链表：";
  ListNode *curr = right_shift_k_01(node, k);
  print_linked_list(curr);

  free_linked_list(curr);
}
void test_02() {
  cout << "方式二：" << endl;
  vector<int> nums = {0, 1, 2, 3, 4, 7, 8};
  ListNode *node = convert_linked_list(nums);
  cout << "初始链表：";
  print_linked_list(node);

  int k = 3;
  cout << "右移 " << k << " 个单位的链表：";
  ListNode *curr = right_shift_k_02(node, k);
  print_linked_list(curr);

  free_linked_list(curr);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}