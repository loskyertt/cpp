#include "solution.hpp"
#include <algorithm>
#include <vector>

std::vector<int> Solution::twoSum(std::vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        if (nums[left] + nums[right] == target) {
            break;
        } else if (nums[left] + nums[right] > left) {
            right--;
        } else {
            left++;
        }
    }

    return { left + 1, right + 1 };
}

std::vector<std::vector<int>> Solution::threeSum(std::vector<int>& nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> res;

    int n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        int x = nums[i];
        if (i && x == nums[i - 1]) { // 跳过重复数字，这里的 i && 是为了确保 i > 0 时才进行重复判断，防止访问 nums[-1] 导致越界（比如 i=0）
            continue;
        }
        if (x + nums[i + 1] + nums[i + 2] > 0) { // 优化一
            break;
        }
        if (x + nums[n - 2] + nums[n - 1] < 0) { // 优化二
            continue;
        }
        int j = i + 1, k = n - 1; // j：左指针，k：右指针
        while (j < k) {
            int s = nums[j] + nums[k] + x;
            if (s > 0) {
                k--;
            } else if (s < 0) {
                j++;
            } else {
                res.push_back({ x, nums[j], nums[k] });
                for (j++; j < k && nums[j] == nums[j - 1]; j++) // 跳过重复的左指针值
                    ;
                for (k--; k > j && nums[k] == nums[k + 1]; k--) // 跳过重复的右指针值
                    ;
            }
        }
    }

    return res;
}
