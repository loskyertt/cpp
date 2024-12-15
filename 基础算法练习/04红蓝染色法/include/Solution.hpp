#pragma once

#include <vector>

class Solution {
    int lower_bound(std::vector<int>& nums, int target);

public:
    std::vector<int> searchRange(std::vector<int>& nums, int target);
};