#include <climits>
#include <cstdlib>
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

/* 去重节点 */
void remove_duplicate(ListNode *head) {
  // 创建一个哈希表用于存储节点值
  unordered_set<int> set_list;
  ListNode *curr = head->next, *prev = head;

  while (curr) {
    // 如果在哈希表中找到了该节点的值，就进行去除
    if (set_list.find(abs(curr->val)) != set_list.end()) {
      ListNode *temp = curr;
      curr = curr->next;
      prev->next = curr;
      delete temp;
    } else {
      set_list.insert(abs(curr->val));
      prev = curr;
      curr = curr->next;
    }
  }
}

void test_01() {
  vector<int> nums = {21, -15, -15, -7, 15};
  ListNode *head = convert_linked_list(nums);
  cout << "初始链表为：";
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