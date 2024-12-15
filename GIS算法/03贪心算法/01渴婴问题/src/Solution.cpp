#include "Solution.hpp"
#include <algorithm>
#include <iostream>
#include <ostream>

bool Solution::compare(Drink a, Drink b)
{
    return a.satisfaction > b.satisfaction;
}

void Solution::distribute(std::vector<Drink>& drinks, int target)
{
    // 按满意度降序排序
    std::sort(drinks.begin(), drinks.end(), Solution::compare);

    int totalConsumed = 0; // 已喝的总量
    double totalSatisfaction = 0.0; // 满意度总和

    // 贪心分配饮料
    for (int i = 0; i < drinks.size() && totalConsumed < target; i++) {
        int drinkAmount = std::min(drinks[i].amount, target - totalConsumed); // 当前饮料能喝多少
        totalConsumed += drinkAmount;
        totalSatisfaction += drinkAmount * drinks[i].satisfaction;
    }

    // 输出结果
    if (totalConsumed == target) {
        std::cout << "Total Satisfaction : " << totalSatisfaction << std::endl;
    } else {
        std::cout << "Not enough drink to satisfy the thirst!" << std::endl;
    }
}
