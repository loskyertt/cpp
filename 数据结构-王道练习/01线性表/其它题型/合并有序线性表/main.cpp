#include "arr.hpp"
#include "linked_list.hpp"
#include <climits>
#include <iostream>

using std::cout;
using std::endl;

void test_linked_list() {
  vector<int> nums1 = {1, 3, 4, 5, 9, 10, 11};
  vector<int> nums2 = {1, 2, 3, 6, 8, 12};

  ListNode *head1 = new ListNode(INT_MAX);
  ListNode *head2 = new ListNode(INT_MAX);

  create_linklist(head1, nums1);
  create_linklist(head2, nums2);

  cout << "head1: ";
  print_list(head1->next);
  cout << "head2: ";
  print_list(head2->next);

  ListNode *head3 = merge_linklist_enumerate(head1, head2);
  cout << "枚举法实现：head3: ";
  print_list(head3->next);
}

void test_vector() {
  vector<int> nums1 = {1, 3, 4, 5, 9, 10, 11};
  vector<int> nums2 = {1, 2, 3, 6, 8, 12};

  cout << "初始数组：" << endl;
  cout << "L1: ";
  print_vector(nums1);
  cout << "L2: ";
  print_vector(nums2);

  vector<int> res = merege_array(nums1, nums2);

  cout << "合并后的数组：";
  print_vector(res);
}

int main() {
  test_linked_list();
  cout << endl;
  test_vector();

  return 0;
}