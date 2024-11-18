#include "schedule.hpp"

void buildSchedule(vector<vector<int>>& schedule, int start, int n)
{
    // 递归终止条件
    if (n == 1) {
        schedule[start][0] = start + 1;
        return;
    }

    int half = n / 2;
    // 递归构建左、右子组的赛程
    buildSchedule(schedule, start, half);
    buildSchedule(schedule, start + half, half);

    // 合并左右子组的赛程
    for (int i = 0; i < half; ++i) {
        for (int j = 0; j < half; ++j) {
            schedule[start + i][half + j] = schedule[start + half + i][j];
            schedule[start + half + i][half + j] = schedule[start + i][j];
        }
    }
}