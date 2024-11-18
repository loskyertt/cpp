#include "point.hpp"
#include <algorithm>
#include <cmath>
#include <limits>

double distance(const Point& a, const Point& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

bool compareByX(const Point& a, const Point& b)
{
    return a.x < b.x;
}

bool compareByY(const Point& a, const Point& b)
{
    return a.y < b.y;
}

double closestPair(vector<Point>& points, int left, int right, vector<Point>& temp)
{
    // 基本情况：当点数少于等于 3 时，直接暴力计算
    if (right - left <= 3) {
        double minDist = numeric_limits<double>::max();
        for (int i = left; i < right; i++) {
            for (int j = i + 1; j < right; j++) {
                minDist = min(minDist, distance(points[i], points[j]));
            }
        }
        // 按 y 坐标排序，为了合并时的优化
        sort(points.begin() + left, points.begin() + right, compareByY);
        return minDist;
    }

    // 分割点
    int mid = (left + right) / 2;
    double midX = points[mid].x;

    // 递归计算左右子集的最近点对
    double deltaLeft = closestPair(points, left, mid, temp);
    double deltaRight = closestPair(points, mid, right, temp);
    double delta = min(deltaLeft, deltaRight);

    // 合并阶段：寻找跨越两个子集的最近点对
    merge(points.begin() + left, points.begin() + mid,
        points.begin() + mid, points.begin() + right, temp.begin(), compareByY);
    copy(temp.begin(), temp.begin() + (right - left), points.begin() + left);

    // 筛选 x 坐标在 [midX - delta, midX + delta] 的点
    vector<Point> strip;
    for (int i = left; i < right; ++i) {
        if (abs(points[i].x - midX) < delta) {
            strip.push_back(points[i]);
        }
    }

    // 检查 strip 中的点对
    for (int i = 0; i < strip.size(); ++i) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < delta; ++j) {
            delta = min(delta, distance(strip[i], strip[j]));
        }
    }

    return delta;
}