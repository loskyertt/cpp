#include "solution.hpp"
#include <stack>

stack<int> conversion_oct(int num) {
  stack<int> stack;

  while (num) {
    stack.push(num % 8);
    num = num / 8;
  }

  return stack;
}