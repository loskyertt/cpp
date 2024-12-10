#include "solution.hpp"
#include <iostream>
#include <ostream>
#include <vector>

void test01()
{
    std::vector<int> nums = { 2, 7, 11, 15 };
    int target = 9;

    Solution s1;
    std::vector<int> res = s1.twoSum(nums, target);

    for (int i : res) {
        std::cout << i << " ";
    }
}

void test02()
{
    std::vector<int> nums = { -1,
        0,
        1,
        2,
        -1,
        -4 };
    Solution s2;
    std::vector<std::vector<int>> res = s2.threeSum(nums);

    for (auto sub_res : res) {
        for (int num : sub_res) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    // test01();
    test02();

    return 0;
}