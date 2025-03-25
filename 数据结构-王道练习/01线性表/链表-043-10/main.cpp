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

/* 判断 B 是否是 A 的连续子序列 */
bool is_sub_sequence(ListNode *A, ListNode *B) {
  ListNode *curr_A = A, *curr_B = B, *prev_A = A;
  // 注意这里要同时判断 curr_A 和 curr_B 是否指向空。当 B 是 A 的连续子序列，curr_B 最后会指向空节点，反之，curr_A 最后会指向空节点
  while (curr_B && curr_A) {
    // 如果相等，则 curr_A 和 curr_B 都往后移一个单位
    if (curr_A->val == curr_B->val) {
      curr_A = curr_A->next;
      curr_B = curr_B->next;
    }
    // 不相等的话，B 就从头开始比较，A 就从上次起始比较的节点的下一个节点开始比较
    else {
      curr_A = prev_A->next;
      prev_A = prev_A->next;
      curr_B = B;
    }
  }

  // 如果 B 是 A 的连续子序列，说明最后 curr_B 最后一定会指向空节点（完全遍历完 B）
  if (!curr_B) {
    return true;
  } else {
    return false;
  }
}

void test() {
  vector<int> nums_A = {1, 4, 5, 5, 3, 6, 7, 9};
  vector<int> nums_B = {5, 5, 1, 3};

  ListNode *A = convert_linked_list(nums_A);
  ListNode *B = convert_linked_list(nums_B);

  if (is_sub_sequence(A->next, B->next)) {
    cout << "B 是 A 的连续子序列。" << endl;
  } else {
    cout << "不是！" << endl;
  }

  free_linked_list(A);
  free_linked_list(B);
}

int main() {
  test();

  return 0;
}