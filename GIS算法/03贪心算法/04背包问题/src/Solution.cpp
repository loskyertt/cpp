#include "Solution.hpp"
#include <algorithm>

bool Solution::compare(Item a, Item b)
{
    return (a.value / a.weight) > (b.value / b.weight);
}

double Solution::fractionalKnapsack(double W, std::vector<Item>& items)
{
    // 按单位重量价值降序排序
    std::sort(items.begin(), items.end(), Solution::compare);

    double totalValue = 0.0; // 总收益
    double currentWeight = 0.0; // 当前背包已装载的重量

    for (auto item : items) {
        if (currentWeight + item.weight <= W) {
            // 完全装入物品
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // 部分装入物品
            double remainingWeight = W - currentWeight; // 剩余容量
            totalValue += item.value * (remainingWeight / item.weight);
            break;
        }
    }

    return totalValue;
}
