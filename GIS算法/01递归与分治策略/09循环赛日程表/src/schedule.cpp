#include "schedule.hpp"

void buildSchedule(vector<vector<int>>& schedule, int i, int j, int n)
{
    int mid = n / 2;
    if (n == 2) { // 当递归到只有两个选手时，i=1, j=2, n=2
        schedule[i][n - 1] = i; // 左上角为1
        schedule[i][n] = j; // 右上角为2
        schedule[j][n - 1] = j; // 左下角为2
        schedule[j][n] = i; // 右下角为1
    } else {
        buildSchedule(schedule, i, i + mid - 1, mid); // 递归一半 mid，开始为 i，结束为 i 到 mid 的个数，即 i+mid-1，规模为 mid
        buildSchedule(schedule, i + mid, j, mid); // 递归另一半 mid，开始为 i+mid，j，规模为 mid
        // 此for循环中，需要复制规模为mid行mid列，一趟循环先复制第n列，再一趟循环复制第n-1列，直到第mid+1列
        // 对于复制的下标的确定，可以想象n=2*2个选手时的下标跟着下面的循环走一遍
        for (int k1 = n; k1 > mid; k1--) {
            for (int k2 = i; k2 <= i + mid - 1; k2++) { // 将左下角的数据复制到右上角
                schedule[k2][k1] = schedule[k2 + mid][k1 - mid];
            }
            for (int k2 = i + mid; k2 <= i + n - 1; k2++) {
                schedule[k2][k1] = schedule[k2 - mid][k1 - mid]; // 将左上角的数据复制到右下角
            }
        }
    }
}
