#pragma once

/* 活动结构体 */
#include <vector>
struct Activity {
    int start;
    int end;
};

class Solution {
public:
    static bool compare(Activity a, Activity b);

    std::vector<Activity> selectActivites(std::vector<Activity>& activities);
};