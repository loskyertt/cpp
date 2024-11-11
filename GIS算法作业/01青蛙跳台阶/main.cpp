#include "frogJump.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "请输入台阶数: ";
    cin >> n;
    cout << "青蛙跳上" << n << "级台阶的总跳法数为: " << frog_jump(n) << endl;
    return 0;
}