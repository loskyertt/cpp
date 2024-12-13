#include "Solution.hpp"
#include <algorithm>
#include <unordered_set>

int Solution::minSubArrayLen(int target, std::vector<int>& nums)
{
    int n = nums.size(), ans = n + 1, sum = 0, left = 0;
    for (int right = 0; right < n; right++) {
        sum += nums[right];
        while (sum - nums[left] >= target) {
            sum -= nums[left++];
        }
        if (sum >= target) {
            ans = std::min(ans, right - left + 1);
        }
    }
    return ans <= n ? ans : 0;
}

int Solution::numSubarrayProductLessThanK(int target, std::vector<int>& nums)
{
    if (target <= 1) {
        return 0;
    }

    int ans = 0, prod = 1, left = 0;
    for (int right = 0; right < nums.size(); right++) {
        prod *= nums[right];
        while (prod >= target) {
            prod /= nums[left++];
        }
        ans += right - left + 1;
    }

    return ans;
}

int Solution::lengthOfLongestSubstring(std::string s)
{
    int n = s.length(), ans = 0, left = 0;
    std::unordered_set<char> window; // 维护从下标 left 到下标 right 的字符
    for (int right = 0; right < n; right++) {
        char c = s[right];

        // 如果窗口内已经包含 c，那么再加入一个 c 会导致窗口内有重复元素
        // 所以要在加入 c 之前，先移出窗口内的 c
        while (window.contains(c)) {
            window.erase(s[left]);
            left++;
        }
        window.insert(c);
        ans = std::max(ans, right - left + 1);
    }

    return ans;
}
