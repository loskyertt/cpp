#include "fib.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n = 5;

    // int res = fib(n);

    vector<int> mem(n + 1, 0);
    // int res = fib_mem(n, mem);

    int res = fib_dp(n);

    cout << "第 " << n << " 项的结果是：" << res << endl;
}