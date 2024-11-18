#pragma once

#include <functional>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>> topKHeap(vector<int>& nums, int k);