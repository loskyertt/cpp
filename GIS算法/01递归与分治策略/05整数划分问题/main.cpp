#include "partition.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n = 6;
    // int res = partition(6, 6);
    int res = partitionDP(6, 6);
    cout << "可以拆分的总数是：" << res << endl;
    return 0;
}