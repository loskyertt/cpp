#include "schedule.hpp"
#include <iostream>
#include <vector>

int main()
{
    int k = 2;
    int size = 1 << k;
    vector<vector<int>> schedule(size + 1, vector<int>(size + 1, 0));
    buildSchedule(schedule, 1, size, size);

    for (auto sub_table : schedule) {
        for (auto day : sub_table) {
            cout << day << " ";
        }
        cout << endl;
    }

    return 0;
}