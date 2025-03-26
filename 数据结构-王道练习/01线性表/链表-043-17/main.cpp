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

/* 获取倒是第 k 个节点的值 */
int get_k(ListNode *head, int k) {

  ListNode *slow = head, *fast = head;
  int count = k;
  while (count > 0) {
    fast = fast->next;
    count--;
    // 如果此时 fast 走到空节点了，但是 count 还大于 0，说明没有走完，k 的大小越界了
    if (!fast && count > 0) {
      return 0;
    }
  }

  while (fast) {
    slow = slow->next;
    fast = fast->next;
  }

  cout << "倒数第 " << k << " 个节点的值为：" << slow->val << endl;
  return 1;
}

void test_01() {
  // 长度只能为偶数
  vector<int> nums = {1, 2, 1, 20, 6, 8, 10, 9};
  ListNode *node = convert_linked_list(nums);

  if (get_k(node, 9) == 0) {
    cout << "没有找到！" << endl;
  }

  free_linked_list(node);
}

int main() {
  test_01();

  return 0;
}