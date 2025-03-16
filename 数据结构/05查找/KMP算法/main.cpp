#include <iostream>
#include <vector>

using namespace std;

int kmp(string main, string pattern) {
  int n = main.size();
  int m = pattern.size();
  string s = pattern + "#" + main;
  vector<int> pi(s.size(), 0);
  for (int i = 1; i < s.size(); i++) {
    int len = pi[i - 1];
    while (len != 0 && s[i] != s[len]) {
      len = pi[len - 1];
    }
    if (s[i] == s[len]) {
      pi[i] = len + 1;
      if (pi[i] == m) {
        return i - 2 * m;
      }
    }
  }

  return -1;
}

int main() {
  string main = "adcbabc", pattern = "abc";
  int res = kmp(main, pattern);
  if (res != -1) {
    cout << "从第 " << res << " 个字符开始匹配" << endl;
  } else {
    cout << "无匹配字符串" << endl;
  }

  return 0;
}