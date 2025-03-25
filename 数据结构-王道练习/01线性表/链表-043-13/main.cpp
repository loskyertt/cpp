#include <climits>
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  int freq;
  ListNode *next;
  ListNode(int x) : val(x), freq(0), next(nullptr) {}
};

/* 打印链表 */
void print_linked_list(ListNode *node) {
  while (node) {
    cout << "val = " << node->val << ", " << "freq = " << node->freq << endl;
    node = node->next;
  }
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

/* 按 freq 排序 */
ListNode *locate(ListNode *head, int target) {
  // 链表带头节点
  ListNode *prev = head, *curr = head->next;        // 找 target 用的
  ListNode *prev_start = head, *start = head->next; // 二次判断用的
  while (curr) {
    // 如果找到目标值，就让当前节点的 freq 加一
    if (curr->val == target) {
      curr->freq += 1;
      // 然后从头开始判断
      while (start) {
        // 找到自己的话，就直接退出这层循环
        if (curr == start) {
          break;
        }
        if (curr->freq >= start->freq) {
          // 断开当前节点
          prev->next = curr->next;
          // 把当前节点连接到前面去
          prev_start->next = curr;
          curr->next = start;
          break;
        }
        prev_start = start;
        start = start->next;
      }

      break;
    }

    prev = curr;
    curr = curr->next;
  }

  return curr;
}

void test() {
  vector<int> nums = {2, 3, 4, 7, 9, 8, 6};
  ListNode *head = convert_linked_list(nums);
  cout << "初始链表：" << endl;
  print_linked_list(head);

  cout << endl;

  cout << "4 访问第一次：" << endl;
  locate(head, 4);
  print_linked_list(head);

  cout << endl;

  cout << "3 访问第一次：" << endl;
  locate(head, 3);
  print_linked_list(head);

  cout << endl;

  cout << "3 访问第二次：" << endl;
  locate(head, 3);
  print_linked_list(head);

  cout << endl;

  cout << "6 访问第一次：" << endl;
  locate(head, 6);
  print_linked_list(head);

  cout << endl;

  cout << "4 访问第二次：" << endl;
  locate(head, 4);
  print_linked_list(head);

  cout << endl;

  cout << "9 访问第一次：" << endl;
  locate(head, 9);
  print_linked_list(head);

  cout << endl;

  cout << "3 访问第三次：" << endl;
  locate(head, 3);
  print_linked_list(head);

  free_linked_list(head);
}

int main() {
  test();

  return 0;
}