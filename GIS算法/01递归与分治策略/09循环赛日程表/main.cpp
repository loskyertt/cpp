#include "schedule.hpp"
#include <iostream>

using namespace std;

int main()
{
    int k;
    cout << "请输入k值 (选手总数为2^k): ";
    cin >> k;
    int n = 1 << k; // 选手总数 n = 2^k

    // 初始化比赛日程表
    vector<vector<int>> schedule(n, vector<int>(n - 1, 0));

    // 构建比赛日程表
    buildSchedule(schedule, 0, n);

    // 输出比赛日程表
    for (int i = 0; i < n; ++i) {
        cout << "选手 " << i + 1 << " 的比赛日程：";
        for (int j = 0; j < n - 1; ++j) {
            cout << schedule[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}