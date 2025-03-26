#include <iostream>
#include <stack>
#include <vector>

using namespace std;

/* 判断序列是否符合出入栈 */
bool is_stack_sequence(vector<char> &sequence) {
  stack<char> s;
  for (char val : sequence) {
    // 如果为 I，就放入栈中
    if (val == 'I') {
      s.push(val);
    }
    // 如果为 O，就出栈
    else {
      // 如果当前栈不为空，就执行出栈
      if (s.empty() != true) {
        s.pop();
      }
      // 如果当前栈为空，但要执行 O 操作，就返回 false，说明是非法序列
      else {
        return false;
      }
    }
  }

  // 如果最终栈为空，就说明是合法序列
  if (s.empty()) {
    return true;
  }

  return false;
}

void test() {
  vector<char> sequence_01 = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};
  vector<char> sequence_02 = {'I', 'O', 'O', 'I', 'O', 'I', 'I', 'O'};
  vector<char> sequence_03 = {'I', 'I', 'I', 'O', 'I', 'O', 'I', 'O'};
  vector<char> sequence_04 = {'I', 'I', 'I', 'O', 'O', 'I', 'O', 'O'};

  if (is_stack_sequence(sequence_01)) {
    cout << "sequence_01 是合法序列！" << endl;
  } else {
    cout << "sequence_01 不是合法序列！" << endl;
  }

  if (is_stack_sequence(sequence_02)) {
    cout << "sequence_02 是合法序列！" << endl;
  } else {
    cout << "sequence_02 不是合法序列！" << endl;
  }

  if (is_stack_sequence(sequence_03)) {
    cout << "sequence_03 是合法序列！" << endl;
  } else {
    cout << "sequence_03 不是合法序列！" << endl;
  }

  if (is_stack_sequence(sequence_04)) {
    cout << "sequence_04 是合法序列！" << endl;
  } else {
    cout << "sequence_04 不是合法序列！" << endl;
  }
}

int main() {
  test();

  return 0;
}