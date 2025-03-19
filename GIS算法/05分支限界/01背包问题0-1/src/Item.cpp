#include "Item.hpp"
#include <algorithm>
#include <queue>

bool operator<(const Node& a, const Node& b)
{
    return a.bound < b.bound; // 按 bound 降序
}

bool cmp(Item a, Item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double bound(Node u, int n, int W, vector<Item>& items)
{
    if (u.weight >= W)
        return 0; // 超重则无效

    double bound = u.profit;
    int totalWeight = u.weight;
    int i = u.level + 1;

    // 尽可能装入完整物品
    while (i < n && totalWeight + items[i].weight <= W) {
        totalWeight += items[i].weight;
        bound += items[i].value;
        i++;
    }

    // 可能部分装入一个物品（计算单位价值部分）
    if (i < n)
        bound += (double)(W - totalWeight) * (double)items[i].value / items[i].weight;

    return bound;
}

int knapsack(int W, vector<Item>& items)
{
    sort(items.begin(), items.end(), cmp); // 按单位价值排序
    int n = items.size();

    priority_queue<Node> pq; // 最大堆（按 bound 降序）
    Node u, v;
    int maxProfit = 0; // 记录当前最优解

    // 根节点（level = -1, profit = 0, weight = 0）
    u.level = -1;
    u.profit = 0;
    u.weight = 0;
    u.bound = bound(u, n, W, items);
    pq.push(u);

    while (!pq.empty()) {
        u = pq.top();
        pq.pop();

        // 只考虑可能优于 maxProfit 的结点
        if (u.bound > maxProfit) {
            // 选择当前物品（左子节点）
            v.level = u.level + 1;
            v.weight = u.weight + items[v.level].weight;
            v.profit = u.profit + items[v.level].value;

            if (v.weight <= W && v.profit > maxProfit)
                maxProfit = v.profit; // 更新最优解

            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit)
                pq.push(v); // 继续扩展

            // 不选择当前物品（右子节点）
            v.weight = u.weight;
            v.profit = u.profit;
            v.bound = bound(v, n, W, items);
            if (v.bound > maxProfit)
                pq.push(v); // 继续扩展
        }
    }

    return maxProfit;
}
