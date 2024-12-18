#include "Solution.hpp"
#include <algorithm>
#include <vector>

bool Solution::compare(Event a, Event b)
{
    if (a.time == b.time) {
        // 时间相同时，结束事件(type=-1)优先于开始事件(type=1)
        return a.type > b.type;
    }

    // 按时间升序排序
    return a.time < b.time;
}

int Solution::minMachines(std::vector<std::pair<int, int>>& tasks)
{
    std::vector<Event> events;

    // 将任务的开始和结束时间转化为事件
    for (auto task : tasks) {
        events.push_back({ task.first, 1 }); // 开始事件
        events.push_back({ task.second, -1 }); // 结束事件
    }

    // 对事件进行排序
    std::sort(events.begin(), events.end(), Solution::compare);

    int maxMachines = 0; // 所需的最小机器数量
    int count = 0;

    // 扫描时间线
    for (auto event : events) {
        count += event.type; // 遇到开始事件 +1，结束事件 -1
        maxMachines = std::max(maxMachines, count);
    }

    return maxMachines;
}
