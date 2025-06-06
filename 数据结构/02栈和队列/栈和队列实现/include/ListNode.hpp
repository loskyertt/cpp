#pragma once

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct BLoopListNode {
  int val;
  BLoopListNode *next, *prev;
  BLoopListNode(int x) : val(x), next(nullptr), prev(nullptr) {}
};
