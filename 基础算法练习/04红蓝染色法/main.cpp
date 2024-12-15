#include "Solution.hpp"
#include <iostream>
#include <vector>

void test()
{
    std::vector<int> nums = { 5, 7, 7, 8, 8, 10 };
    int target = 8;

    Solution s1;
    std::vector<int> res = s1.searchRange(nums, target);

    std::cout << "结果是：";
    for (int ans : res) {
        std::cout << ans << " ";
    }
}

int main()
{
    test();

    return 0;
}