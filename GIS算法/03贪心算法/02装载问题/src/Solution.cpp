#include "Solution.hpp"
#include <algorithm>

int Solution::maxContainers(int n, int c, std::vector<int>& weights)
{
    sort(weights.begin(), weights.end()); // 按重量升序排序

    int totalWeight = 0; // 当前总重量
    int count = 0; // 装载的货物数量

    for (int i = 0; i < n; ++i) {
        if (totalWeight + weights[i] <= c) { // 检查是否可以装载当前货物
            totalWeight += weights[i]; // 更新总重量
            count++; // 增加货物数量
        } else {
            break; // 如果当前货物无法装载，结束循环
        }
    }

    return count; // 返回装载的货物数量
}
