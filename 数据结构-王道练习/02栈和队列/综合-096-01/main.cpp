#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool is_match(string &expression) {
  stack<char> s;

  for (char val : expression) {
    if (val == '(' || val == '[' || val == '{') {
      // 左括号直接入栈
      s.push(val);
    } else if (val == ')' || val == ']' || val == '}') {
      // 检查右括号是否匹配
      if (s.empty())
        return false;

      char top = s.top();
      if ((val == ')' && top != '(') ||
          (val == ']' && top != '[') ||
          (val == '}' && top != '{')) {
        return false;
      }
      s.pop();
    }
  }

  // 最后栈必须为空，表示所有括号都已匹配
  return s.empty();
}

void test() {
  string expressions[] = {
      "{[(7+2)*3-6]/5+[(4+1)*2+1]}*3", // 正确匹配
      "([)]",                          // 不正确的匹配
      "{[}]",                          // 不正确的匹配
      "(())",                          // 正确匹配
      ""                               // 空字符串
  };

  for (string &expr : expressions) {
    cout << "表达式 \"" << expr << "\": "
         << (is_match(expr) ? "括号匹配!" : "不匹配!") << endl;
  }
}

int main() {
  test();
  return 0;
}