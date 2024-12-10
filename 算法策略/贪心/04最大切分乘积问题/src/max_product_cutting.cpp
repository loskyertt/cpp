#include "max_product_cutting.hpp"
#include <cmath>

using namespace std;

int maxProductCutting(int n)
{
    // 当 n <= 3 时，必须切分出一个 1
    if (n <= 3) {
        return 1 * (n - 1);
    }
    // 贪心切分出3 ，a 为 3 的个数，b 为余数
    int a = n / 3;
    int b = n % 3;
    if (b == 1) {
        // 当余数为 1 时，将一对 1*3 转换为 2*2
        return (int)pow(3, a) * 2;
    }
    // 当余数为 0 时，不做处理
    return (int)pow(3, a);
}