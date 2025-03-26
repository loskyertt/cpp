#include <algorithm>
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

/* 求最大孪生和 */
/* 简单循环遍历实现 */
int get_max_val_01(ListNode *node, int length) {
  int max_val = INT_MIN;
  ListNode *curr = node;
  int i = 0;
  while (i < length / 2) {
    ListNode *next_node = curr;
    int j = i;
    while (j < length - i - 1) {
      next_node = next_node->next;
      j++;
    }

    max_val = max(max_val, curr->val + next_node->val);
    curr = curr->next;
    i++;
  }

  return max_val;
}

/* 通过快慢指针实现 */
int get_max_val_02(ListNode *node) {
  ListNode *slow = node, *fast = node, *prev = nullptr;

  // 让 slow 走到后半部分的第一个节点
  while (fast) {
    fast = fast->next->next;
    prev = slow; // 用于记录 slow 的前一个节点（即前半部分的最后一个节点）
    slow = slow->next;
  }

  prev->next = nullptr;

  // 逆转后半部分链表
  ListNode *prev_s = nullptr;
  while (slow) {
    ListNode *temp = slow->next;
    slow->next = prev_s;
    prev_s = slow;
    slow = temp;
  }

  int max_val = INT_MIN;
  // 这时候 prev_s 成为后半部分链表的起始节点，只不过是倒序
  while (node && prev_s) {
    max_val = max(max_val, node->val + prev_s->val);
    node = node->next;
    prev_s = prev_s->next;
  }

  return max_val;
}

void test_01() {
  // 长度只能为偶数
  vector<int> nums = {1, 2, 1, 20, 6, 8, 10, 9};
  ListNode *node = convert_linked_list(nums);

  cout << "简单循环实现：" << endl;
  int max_val = get_max_val_01(node, nums.size());
  cout << "最大孪生和为：" << max_val << endl;

  free_linked_list(node);
}

void test_02() {
  // 长度只能为偶数
  vector<int> nums = {1, 2, 1, 20, 6, 8, 10, 9};
  ListNode *node = convert_linked_list(nums);

  cout << "快慢指针实现：" << endl;
  int max_val = get_max_val_02(node);
  cout << "最大孪生和为：" << max_val << endl;

  free_linked_list(node);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}