#include "Solution.hpp"
#include <algorithm>
#include <vector>

bool Solution::compare(Activity a, Activity b)
{
    return a.end < b.end;
}

std::vector<Activity> Solution::selectActivites(std::vector<Activity>& activities)
{
    // 按结束时间排序
    std::sort(activities.begin(), activities.end(), Solution::compare);

    std::vector<Activity> res;
    int lastEndTime = 0;

    for (auto activity : activities) {
        if (activity.start >= lastEndTime) {
            res.push_back(activity);
            lastEndTime = activity.end;
        }
    }

    return res;
}
