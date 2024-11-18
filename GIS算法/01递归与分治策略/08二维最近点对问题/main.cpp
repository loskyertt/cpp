#include "point.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

// 主函数
int main()
{
    int n;
    cout << "请输入点的个数: ";
    cin >> n;

    vector<Point> points(n);
    cout << "请输入每个点的坐标 (x y):" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    // 按 x 坐标排序
    sort(points.begin(), points.end(), compareByX);

    // 临时数组用于合并
    vector<Point> temp(n);

    // 调用分治法计算最近点对距离
    double minDist = closestPair(points, 0, n, temp);

    cout << "最近点对的距离是: " << minDist << endl;

    return 0;
}