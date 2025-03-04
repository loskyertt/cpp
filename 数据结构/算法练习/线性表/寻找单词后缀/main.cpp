#include <iostream>

using namespace std;

struct ListNode {
  char letter;
  ListNode *next;
  ListNode(char x) : letter(x), next(nullptr) {}
};

void print_list(ListNode *head) {
  ListNode *tmp = head->next;
  while (tmp) {
    cout << tmp->letter << " -> ";
  }

  cout << endl;
}