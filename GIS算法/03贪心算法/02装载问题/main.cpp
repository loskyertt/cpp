#include "Solution.hpp"
#include <iostream>
#include <ostream>
#include <vector>

void test()
{
    std::vector<int> weights = { 10, 20, 30, 5, 15 };
    int target = 50;

    Solution s1;
    int ans = s1.maxContainers(weights.size(), target, weights);

    std::cout << "最多装载：" << ans << "个" << std::endl;
}

int main()
{
    test();

    return 0;
}