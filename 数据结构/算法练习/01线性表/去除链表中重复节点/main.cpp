#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

/* 去除绝对值相等的重复节点 */
void remove_duplicates(ListNode *head) {
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

// void remove_duplicates(ListNode *head) {
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

void print_list(ListNode *head) {
  ListNode *tmp = head->next;
  while (tmp) {
    cout << tmp->val << " -> ";
    tmp = tmp->next;
  }

  cout << endl;
}

int main() {
  ListNode *head = new ListNode(0);
  head->next = new ListNode(21);
  head->next->next = new ListNode(-15);
  head->next->next->next = new ListNode(-15);
  head->next->next->next->next = new ListNode(-7);
  head->next->next->next->next->next = new ListNode(15);

  cout << "初始链表：" << endl;
  print_list(head);

  cout << "去重后的链表：" << endl;
  remove_duplicates(head);
  print_list(head);

  return 0;
}