#pragma once
#include <utility>
#include <vector>

/* 事件结构体：区分开始时间和结束时间*/
struct Event {
    int time; // 时间
    int type; // 类型：1.表示开始时间，-1表示结束事件
    Event(int time, int type)
        : time(time)
        , type(type)
    {
    }
};

class Solution {
public:
    static bool compare(Event a, Event b);

    /* 计算最少机器数量 */
    int minMachines(std::vector<std::pair<int, int>>& tasks);
};