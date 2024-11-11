#pragma once
#include <vector>

using namespace std;

// 模拟比较仪器，返回比较结果：1表示左边轻，-1表示右边轻，0表示两边相等
int compare(const vector<int>& coins, int left, int mid, int right);

int findFakeCoin(const vector<int>& coins, int left, int right);