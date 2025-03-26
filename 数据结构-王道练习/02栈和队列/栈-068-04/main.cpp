#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
  char val;
  ListNode *next;
  ListNode(char x) : val(x), next(nullptr) {}
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
ListNode *convert_linked_list(vector<char> &sequence) {
  // 带头结点
  ListNode *head = new ListNode('L');
  ListNode *curr = head;
  for (char val : sequence) {
    curr->next = new ListNode(val);
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

/* 判断链表对称性：栈实现 */
// 注：也可以通过只让一半元素入栈来实现，但是要注意元素序列是奇数个数的情况（用快慢指针定位到链表的后半部分）
bool is_symmetrical(ListNode *head) {
  stack<char> s;
  ListNode *temp1 = head->next;
  // 把所有链表中元素压入栈，最后栈中的元素出栈序列正好与 head 的相反
  while (temp1) {
    s.push(temp1->val);
    temp1 = temp1->next;
  }

  ListNode *temp2 = head->next;
  // 如果是对称的，栈中的序列（翻转后的）应该和链表的一样
  while (temp2) {
    char val = s.top();
    if (val == temp2->val) {
      temp2 = temp2->next;
      s.pop();
    } else {
      return false;
    }
  }

  return true;
}

void test() {
  vector<char> sequence_01 = {'x', 'y', 'y', 'x'};
  vector<char> sequence_02 = {'x', 'y', 'm', 'y', 'x'};
  vector<char> sequence_03 = {'x', 'y', 'y', 'x', 'x'};

  ListNode *head1 = convert_linked_list(sequence_01);
  ListNode *head2 = convert_linked_list(sequence_02);
  ListNode *head3 = convert_linked_list(sequence_03);

  if (is_symmetrical(head1)) {
    cout << "head1 是对称的！" << endl;

  } else {
    cout << "head1 不是对称的！" << endl;
  }

  if (is_symmetrical(head2)) {
    cout << "head2 是对称的！" << endl;

  } else {
    cout << "head2 不是对称的！" << endl;
  }

  if (is_symmetrical(head3)) {
    cout << "head3 是对称的！" << endl;

  } else {
    cout << "head3 不是对称的！" << endl;
  }

  free_linked_list(head1);
  free_linked_list(head2);
  free_linked_list(head3);
}

int main() {
  test();

  return 0;
}