#include "max_capacity.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> ht = { 3, 8, 5, 2, 7, 7, 3, 4 };
    int res = maxCapacity(ht);

    cout << "最大容量为：" << res << endl;

    return 0;
}