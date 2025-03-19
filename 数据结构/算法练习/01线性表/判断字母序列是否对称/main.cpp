#include <iostream>
#include <string>

using namespace std;

struct ListNode {
  char letter;
  ListNode *prev;
  ListNode *next;
  ListNode(char x) : letter(x), prev(nullptr), next(nullptr) {}
};

/* 打印双向循环链表 */
void print_linklist(ListNode *head) {
  if (!head)
    return;
  cout << head->letter << " -> ";
  ListNode *curr = head->next;
  while (curr != head) {
    cout << curr->letter << " -> ";
    curr = curr->next;
  }
  cout << "(" << head->letter << ")" << endl;
}

/* 字符串转双向循环链表 */
ListNode *word_to_linklist(string word) {
  if (word.length() == 0) {
    cout << "输入的单词不能为空！" << endl;
    return nullptr;
  }

  ListNode *head = new ListNode(word[0]);
  ListNode *curr = head;
  for (int i = 1; i < word.length(); i++) {
    ListNode *newNode = new ListNode(word[i]);
    curr->next = newNode;
    newNode->prev = curr;
    curr = newNode;
  }
  curr->next = head;
  head->prev = curr;

  return head;
}

/* 判断双向循环链表是否对称 */
bool is_symmetric(ListNode *head) {
  if (!head)
    return true;

  ListNode *left = head;
  ListNode *right = head->prev; // 循环链表的尾节点

  while (left->letter == right->letter) {
    // 节点为奇数或偶数的情况，当左右指针相遇
    if (left->next == right->prev || left->next == right) {
      return true;
      break;
    }
    left = left->next;
    right = right->prev;
  }

  return false;
}

void test() {
  string word = "ACBBA";
  ListNode *word_l = word_to_linklist(word);
  print_linklist(word_l);

  if (is_symmetric(word_l)) {
    cout << "字母序列是对称的" << endl;
  } else {
    cout << "字母序列不是对称的" << endl;
  }
}

int main() {
  test();

  return 0;
}
