#include "Solution.hpp"

int Solution::lower_bound(std::vector<int>& nums, int target)
{
    int left = 0, right = (int)nums.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] >= target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

std::vector<int> Solution::searchRange(std::vector<int>& nums, int target)
{
    int start = lower_bound(nums, target);
    if (start == nums.size() || nums[start] != target) {
        return { -1, -1 };
    }

    int end = lower_bound(nums, target + 1) - 1;
    return { start, end };
}
