#include "solution.hpp"
#include <iostream>
#include <vector>

void test01()
{
    Solution s1;
    std::vector<int> nums = { 0,
        1,
        0,
        2,
        1,
        0,
        1,
        3,
        2,
        1,
        2,
        1 };
    int ans = s1.trap_pre_suf(nums);

    std::cout << "总和为：" << ans << std::endl;
}

void test02()
{
    Solution s2;
    std::vector<int> nums = { 0,
        1,
        0,
        2,
        1,
        0,
        1,
        3,
        2,
        1,
        2,
        1 };
    int ans = s2.trap_ptr(nums);

    std::cout << "总和为：" << ans << std::endl;
}

int main()
{
    // test01();
    test02();

    return 0;
}