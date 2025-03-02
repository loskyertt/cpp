#include "solution.hpp"
#include <iostream>
#include <stack>

int main() {
  stack<int> res = conversion_oct(159);

  while (!res.empty()) {

    cout << res.top();
    res.pop();
  }

  return 0;
}