#include "solution.hpp"
#include <algorithm>
#include <vector>

int Solution::trap_pre_suf(std::vector<int>& height)
{
    int n = height.size();
    std::vector<int> pre_max(n); // pre_max[i] 表示从 height[0] 到 height[i] 的最大值
    pre_max[0] = height[0];
    for (int i = 1; i < n; i++) {
        pre_max[i] = std::max(pre_max[i - 1], height[i]);
    }

    std::vector<int> suf_max(n); // suf_max[i] 表示从 height[i] 到 height[n-1] 的最大值
    suf_max[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        suf_max[i] = std::max(suf_max[i + 1], height[i]);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += std::min(pre_max[i], suf_max[i]) - height[i]; // 累加每个水桶能接多少水
    }

    return ans;
}

int Solution::trap_ptr(std::vector<int>& height)
{
    int ans = 0, left = 0, right = height.size() - 1, pre_max = 0, suf_max = 0;
    while (left < right) {
        pre_max = std::max(pre_max, height[left]);
        suf_max = std::max(suf_max, height[right]);
        ans += pre_max < suf_max ? pre_max - height[left++] : suf_max - height[right--];
    }
    return ans;
}
