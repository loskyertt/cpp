#pragma once

#include <vector>

class Solution {
public:
    /* 两数之和 */
    std::vector<int> twoSum(std::vector<int>& nums, int target);

    /* 三数之和 */
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums);
};