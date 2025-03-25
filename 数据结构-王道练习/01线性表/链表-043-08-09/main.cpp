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

/* 找到链表的交集：使用枚举的方式 */
void get_intersection_enumerate(ListNode *L1, ListNode *L2, ListNode *L3) {
  ListNode *curr1 = L1->next;
  ListNode *tail = L3; // 使用 tail 来构建 L3 链表

  while (curr1) {
    ListNode *curr2 = L2->next; // 重新回到 L2 链表的起点
    while (curr2) {
      if (curr1->val == curr2->val) {
        ListNode *newNode = new ListNode(curr1->val);
        tail->next = newNode;
        tail = newNode;
        break; // 找到交集后跳出内层循环
      }
      curr2 = curr2->next; // 递增 curr2
    }
    curr1 = curr1->next; // 递增 curr1
  }
}

/* 将 A 链表和 B 链表中公共元素构成链表 C */
ListNode *get_intersection_01(ListNode *A, ListNode *B) {
  ListNode *C = new ListNode(INT_MAX);
  ListNode *curr_A = A->next, *curr_B = B->next, *curr_C = C;
  while (curr_A && curr_B) {
    // 如果元素相同
    if (curr_A->val == curr_B->val) {
      curr_C->next = new ListNode(curr_A->val);
      curr_C = curr_C->next;
      // A 和 B 同时移动一个节点
      curr_A = curr_A->next;
      curr_B = curr_B->next;
    } else {
      // 把小的节点往后移，找一下后面大的节点的元素满不满足条件
      int max_val = max(curr_A->val, curr_B->val);
      curr_A = curr_A->val == max_val ? curr_A : curr_A->next;
      curr_B = curr_B->val == max_val ? curr_B : curr_B->next;
    }
  }
  return C;
}

/* 求 A 与 B 的交集，并存放于 A 链表中 */
void get_intersection_02(ListNode *A, ListNode *B) {
  ListNode *prev_A = A, *curr_A = A->next, *curr_B = B->next;
  while (curr_A && curr_B) {
    if (curr_A->val == curr_B->val) {
      prev_A = curr_A;
      curr_A = curr_A->next;
      curr_B = curr_B->next;
    }
    // 如果 A 的值小于 B 的值，就把 curr_A 指向的当前节点释放掉，并且后移一个单位
    else if (curr_A->val < curr_B->val) {
      ListNode *temp = curr_A;
      curr_A = curr_A->next;
      prev_A->next = curr_A;
      delete temp;
    } else {
      curr_B = curr_B->next;
    }
  }

  // 删除 A 中多余的节点（链表 A 比 链表 B 长的情况）
  while (prev_A->next) {
    ListNode *temp = prev_A->next;
    prev_A->next = temp->next;
    delete temp;
  }
}

void test_01() {

  vector<int> nums_1 = {1, 2, 7, 10, 11};
  ListNode *L1 = convert_linked_list(nums_1);

  vector<int> nums_2 = {3, 2, 4, 9, 11, 14};
  ListNode *L2 = convert_linked_list(nums_2);

  cout << "L1: ";
  print_linked_list(L1->next);
  cout << "L2: ";
  print_linked_list(L2->next);

  cout << "L3: ";
  ListNode *L3 = new ListNode(INT_MAX);
  get_intersection_enumerate(L1, L2, L3);
  print_linked_list(L3->next);

  free_linked_list(L1);
  free_linked_list(L2);
  free_linked_list(L3);
}

// 只能处理递增有序的情况
void test_02() {
  vector<int> nums_A = {1, 3, 4, 5, 8, 9, 10, 14, 15};
  ListNode *A = convert_linked_list(nums_A);

  vector<int> nums_B = {1, 2, 4, 6, 7, 8, 10};
  ListNode *B = convert_linked_list(nums_B);

  cout << "A: ";
  print_linked_list(A);
  cout << "B: ";
  print_linked_list(B);

  cout << "C: ";
  ListNode *C = get_intersection_01(A, B);
  print_linked_list(C);

  free_linked_list(A);
  free_linked_list(B);
  free_linked_list(C);
}

// 只能处理递增有序的情况
void test_03() {
  vector<int> nums_A = {1, 3, 4, 5, 8, 9, 10, 14, 15};
  ListNode *A = convert_linked_list(nums_A);

  vector<int> nums_B = {1, 2, 4, 6, 7, 8, 10};
  ListNode *B = convert_linked_list(nums_B);

  cout << "初始 A: ";
  print_linked_list(A);
  cout << "初始 B: ";
  print_linked_list(B);

  cout << "处理后的 A: ";
  get_intersection_02(A, B);
  print_linked_list(A);

  free_linked_list(A);
  free_linked_list(B);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}