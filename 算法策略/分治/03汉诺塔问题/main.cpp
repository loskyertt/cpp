#include "hanoi.hpp"
#include <iostream>

int main()
{
    // 测试原始位置和借助的位置
    vector<int> A = { 1, 2, 3 };
    vector<int> B;
    vector<int> C;

    solveHanota(A, B, C);

    // 打印结果
    std::cout << "解: ";
    for (const auto& x : C) {
        std::cout << x << ' ';
    }
    std::cout << '\n';

    return 0;
}