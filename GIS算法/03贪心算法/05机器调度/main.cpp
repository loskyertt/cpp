#include "Solution.hpp"
#include <iostream>
#include <ostream>
#include <utility>
#include <vector>

void test()
{
    // std::vector<std::pair<int, int>> tasks = { { 1, 4 }, { 2, 5 }, { 3, 6 }, { 7, 8 }, { 5, 9 } };
    std::vector<std::pair<int, int>> tasks = { { 0, 2 },
        { 3, 7 },
        { 4, 7 },
        { 9, 11 },
        { 7, 10 },
        { 1, 5 },
        { 6, 8 } };

    Solution s1;

    int maxMachines = s1.minMachines(tasks);

    std::cout << "最大机器数量：" << maxMachines << std::endl;
}

int main()
{
    test();

    return 0;
}