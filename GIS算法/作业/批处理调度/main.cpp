#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 作业结构体
struct Job {
    int id; // 作业编号
    int t1; // 机器1上的处理时间
    int t2; // 机器2上的处理时间
};

// 比较函数，用于排序作业
bool compareJobs(const Job& a, const Job& b)
{
    if (a.t1 < a.t2 && b.t1 < b.t2) {
        return a.t1 < b.t1; // 机器1处理时间较小的优先
    } else if (a.t1 >= a.t2 && b.t1 >= b.t2) {
        return a.t2 > b.t2; // 机器2处理时间较小的优先
    }
    return a.t1 < a.t2; // 机器1优先的放前面
}

// 计算完成时间和
int calculateMinCompletionTime(vector<Job>& jobs)
{
    // 按照排序规则对作业进行排序
    sort(jobs.begin(), jobs.end(), compareJobs);

    // 模拟调度
    int time1 = 0, time2 = 0; // 机器1和机器2的当前完成时间
    int totalCompletionTime = 0;

    for (const auto& job : jobs) {
        time1 += job.t1; // 机器1完成当前作业的时间
        time2 = max(time2, time1) + job.t2; // 机器2完成当前作业的时间
        totalCompletionTime += time2; // 累加完成时间
    }

    return totalCompletionTime;
}

int main()
{
    int n;
    cout << "请输入作业数量 n: ";
    cin >> n;

    vector<Job> jobs(n);
    cout << "依次输入每个作业在机器1和机器2上的处理时间 (t1 t2):" << endl;
    for (int i = 0; i < n; ++i) {
        jobs[i].id = i + 1;
        cin >> jobs[i].t1 >> jobs[i].t2;
    }

    int minCompletionTime = calculateMinCompletionTime(jobs);

    cout << "最优调度顺序为:" << endl;
    for (const auto& job : jobs) {
        cout << "J" << job.id << " ";
    }
    cout << endl;

    cout << "最小完成时间和为: " << minCompletionTime << endl;

    return 0;
}
