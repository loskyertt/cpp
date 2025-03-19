#pragma once

#include <vector>
using namespace std;

/* 物品结构体 */
struct Item {
    int weight, value;
};

/* 结点结构体 */
struct Node {
    int level; // 当前物品索引（层数）
    int profit; // 当前已选物品的总价值
    int weight; // 当前已选物品的总重量
    double bound; // 乐观估计的最大可能价值（用于剪枝）
};

// 比较函数
bool operator<(const Node& a, const Node& b);

/* 按单位价值从高到低排序 */
bool cmp(Item a, Item b);

/* 计算上界函数（贪心策略） */
double bound(Node u, int n, int W, vector<Item>& items);

/* 分支限界法求解 0-1 背包问题 */
int knapsack(int W, vector<Item>& items);