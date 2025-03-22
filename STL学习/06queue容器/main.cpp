#include <iostream>
#include <queue>

using namespace std;

/* 队列的基本使用 */
void test_01() {
  queue<int> q;
  q.push(1);
  q.push(3);
  q.push(2);
  q.push(6);
  q.push(8);
  q.push(10);

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }

  cout << endl;
}

int main() {
  test_01();

  return 0;
}