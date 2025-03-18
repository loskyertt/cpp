#include <iostream>
#include <string>

using namespace std;

template <class T>
T twice(T val) {
  return val * 2;
}

string twice(string val) {
  return val + val;
}

int main() {
  cout << twice<int>(21) << endl;
  cout << twice<float>(3.14f) << endl;
  cout << twice<double>(2.718) << endl;

  // cout << twice("hello") << endl;    // 这种方式会出错！会和 T twice(T val) 进行重载
  cout << twice(string("hello")) << endl;

  return 0;
}