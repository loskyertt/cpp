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
void print_linked_list(ListNode *head) {
  cout << "head -> ";
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << "nullptr" << endl;
}

/* 数组转链表 */
ListNode *create_linked_list(vector<int> &nums) {
  ListNode *head = new ListNode(INT_MAX);
  ListNode *current = head;

  for (int num : nums) {
    ListNode *new_node = new ListNode(num);
    current->next = new_node;
    current = current->next;
  }

  return head;
}

void test_01() {
  vector<int> nums = {1, 2, 3, 4, 5, 6};
  ListNode *node = create_linked_list(nums);
  print_linked_list(node->next);
}

int main() {
  test_01();

  return 0;
}