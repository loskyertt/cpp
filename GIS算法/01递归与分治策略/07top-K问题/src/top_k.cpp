#include "top_k.hpp"
#include <functional>
#include <queue>
#include <vector>

priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int>& nums, int k)
{
    // 初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> heap;
    // 将数组的前 k 个元素入堆
    for (int i = 0; i < k; i++) {
        heap.push(nums[i]);
    }

    // 从第 k+1 个元素开始，保持堆的长度为 k
    for (int i = k; i < nums.size(); i++) {
        if (nums[i] > heap.top()) {
            heap.pop();
            heap.push(nums[i]);
        }
    }

    return heap;
}