#include "Solution.hpp"
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

void test01()
{
    std::vector<int> nums = { 2,
        3,
        1,
        2,
        4,
        3 };

    int target = 7;

    Solution s1;
    int ans = s1.minSubArrayLen(target, nums);

    std::cout << "最短长度为：" << ans << std::endl;
}

void test02()
{
    std::vector<int> nums = { 10, 5, 2, 6 };

    int target = 100;

    Solution s2;
    int ans = s2.numSubarrayProductLessThanK(target, nums);

    std::cout << ans << " 个子数组。" << std::endl;
}

void test03()
{
    std::string s = "abcabcbb";

    Solution s3;
    int ans = s3.lengthOfLongestSubstring(s);

    std::cout << "无重复字符的最长字符串是：" << ans << std::endl;
}

int main()
{
    // test01();
    // test02();
    test03();

    return 0;
}