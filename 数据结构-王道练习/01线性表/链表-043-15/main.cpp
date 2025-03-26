#include <climits>
#include <iostream>
#include <unordered_set>
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

/* 释放有环链表的内存 */
void free_loop_linked_list(ListNode *head) {
  unordered_set<ListNode *> set_list;
  // 没有找到重复节点，就一直运行
  while (head && set_list.find(head) == set_list.end()) {
    set_list.insert(head);
    ListNode *temp = head;
    head = head->next;
    delete temp;
  }
}

/* 判断链表是否存在环 */
/* 通过哈希表判断  */
bool is_existed_loop_01(ListNode *head) {
  unordered_set<ListNode *> set_list;

  while (head) {
    if (set_list.find(head) != set_list.end()) {
      return true;
    }

    set_list.insert(head);
    head = head->next;
  }

  return false;
}

/* 通过快慢指针来判断 */
bool is_existed_loop_02(ListNode *head) {
  ListNode *slow = head, *fast = head;
  // 如果有环，最终 slow 和 fast 一定会相遇
  while (fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
      return true;
    }
  }

  return false;
}

void test_01() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  // head->next->next->next->next->next->next = head->next->next->next;

  cout << "哈希表实现：" << endl;

  if (is_existed_loop_01(head)) {
    cout << "链表有环！" << endl;
  } else {
    cout << "链表无环！" << endl;
  }

  free_loop_linked_list(head);
}

void test_02() {
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);
  // head->next->next->next->next->next->next = head->next->next->next;

  cout << "快慢指针实现：" << endl;

  if (is_existed_loop_02(head)) {
    cout << "链表有环！" << endl;
  } else {
    cout << "链表无环！" << endl;
  }

  free_loop_linked_list(head);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}