#include <iostream>
#include <stack>

using namespace std;

void test_01() {
  stack<int> s;
  s.push(1);
  s.push(3);
  s.push(6);
  s.push(5);
  s.push(8);

  while (!s.empty()) {
    cout << s.top() << " ";
    s.pop();
  }

  cout << endl;
}

int main() {
  test_01();

  return 0;
}