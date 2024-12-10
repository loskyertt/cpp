#include "max_product_cutting.hpp"
#include <iostream>

using namespace std;

int main()
{
    int n = 10;
    int MAX_res = maxProductCutting(n);

    cout << "最大乘积为：" << MAX_res << endl;

    return MAX_res;
}