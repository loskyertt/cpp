#pragma once

#include <vector>

using namespace std;

void buildSchedule(
    vector<vector<int>>& schedule, // 日程表二维数组
    int i, // 起始选手编号
    int j, // 结束选手编号
    int n // 当前处理的选手数量
);