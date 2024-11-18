#include "top_k.hpp"
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main()
{
    vector<int> nums = { 1, 7, 6, 3, 2 };
    priority_queue<int, vector<int>, greater<int>> heap = topKHeap(nums, 3);

    while (!heap.empty()) {
        cout << heap.top() << " ";
        heap.pop();
    }
    cout << endl;

    return 0;
}