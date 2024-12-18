#include "Solution.hpp"
#include <iostream>
#include <ostream>
#include <vector>

void test()
{
    std::vector<Item> items = { Item(10, 60), Item(20, 100), Item(30, 120) };
    double W = 50.0;

    Solution s1;
    double totalValue = s1.fractionalKnapsack(W, items);

    std::cout << "最高总价值：" << totalValue << std::endl;
}

int main()
{
    test();

    return 0;
}