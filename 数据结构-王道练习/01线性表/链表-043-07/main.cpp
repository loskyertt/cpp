#include <climits>
#include <cstdio>
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

/* 去除绝对值相等的重复节点 */
void remove_duplicate_01(ListNode *head) {
  unordered_set<int> screen;
  // 在这里的 current 是始终指向当前遍历的节点，而 current->next 则是指向要检查是否重复的节点，所以不需要维护 prev 节点
  ListNode *current = head;

  while (current && current->next) {
    if (screen.find(abs(current->next->val)) != screen.end()) {
      // 不相等代表有重复元素
      ListNode *tmp = current->next;
      // 这里删除的实际上是 current->next 指向的节点（tmp 节点），所以只需要更新 current->next，使其指向 current->next->next
      current->next = current->next->next;
      delete tmp;
    } else {
      screen.insert(abs(current->next->val));
      current = current->next;
    }
  }
}

// void remove_duplicate_01(ListNode *head) {
//   unordered_set<int> screen;

//   ListNode *current = head->next;
//   ListNode *prev = head; // prev 用来跟踪当前节点的前一个节点

//   while (current) {
//     if (screen.find(abs(current->val)) != screen.end()) {
//       // 如果当前节点的绝对值已经出现过，删除当前节点
//       ListNode *tmp = current;
//       prev->next = current->next; // 更新前一个节点的 next 指针
//       current = current->next;    // 移动到下一个节点
//       delete tmp;                 // 释放当前节点的内存
//     } else {
//       // 如果没有出现过，加入集合并移动到下一个节点
//       screen.insert(abs(current->val));
//       prev = current;          // 更新 prev 指针
//       current = current->next; // 移动到下一个节点
//     }
//   }
// }

/* 去除重复节点，链表递增有序，按照前面顺序表去重的思路 */
void remove_duplicate_02(ListNode *head) {
  ListNode *slow = head->next, *fast = slow->next;
  while (fast) {
    if (slow->val != fast->val) {
      slow = slow->next;
      slow->val = fast->val;
    }

    fast = fast->next;
  }

  // 删除 slow 后面的节点，因为 slow 指向的就是去重后的链表的最后一个节点
  while (slow->next) {
    ListNode *tmp = slow->next;
    slow->next = tmp->next;
    delete tmp;
  }
}

// 去除重复节点（按绝对值），链表无序
void test_01() {
  vector<int> nums = {0, 21, -15, -15, -7, 15};
  ListNode *head = convert_linked_list(nums);

  cout << "初始链表：";
  print_linked_list(head);

  cout << "去重后的链表：";
  remove_duplicate_01(head);
  print_linked_list(head);

  free_linked_list(head);
}

// 去除重复节点，链表递增有序
void test_02() {
  vector<int> nums = {7, 10, 21, 30, 42, 42, 42, 70, 70};
  ListNode *head = convert_linked_list(nums);

  cout << "初始链表：";
  print_linked_list(head);

  cout << "去重后的链表：";
  remove_duplicate_02(head);
  print_linked_list(head);

  free_linked_list(head);
}

int main() {
  test_01();
  cout << endl;
  test_02();

  return 0;
}