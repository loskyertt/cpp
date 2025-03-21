#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

/* 打印 deque 中的元素 */
void print_deque(const deque<int> &d) {
  for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
    cout << *it << " ";
  }

  cout << endl;
}

// deque 构造：操作和 vector 很像，也可以用 push_back 这些
void test_01() {
  deque<int> d1 = {1, 2, 3, 4, 5, 6, 7, 8};

  cout << "d1: ";
  print_deque(d1);

  d1.push_back(-2);
  cout << "在尾部添加了 -2 后的：";
  print_deque(d1);

  // 在容器头部插入元素
  d1.push_front(-2);
  cout << "在头部添加了 -2 后的：";
  print_deque(d1);

  // 删除第一个元素
  d1.pop_front();
  cout << "删除第一个元素：";
  print_deque(d1);

  deque<int> d2;
  d2.push_back(10);
  d2.push_back(11);
  d2.push_back(13);

  cout << "初始 d2: ";
  print_deque(d2);

  d2.insert(d2.begin(), d1.begin(), d1.end());
  cout << "插入 d1 后的 d2: ";
  print_deque(d2);

  // 排序
  cout << "对 d2 排序后的：";
  sort(d2.begin(), d2.end());
  print_deque(d2);
}

int main() {
  test_01();

  return 0;
}