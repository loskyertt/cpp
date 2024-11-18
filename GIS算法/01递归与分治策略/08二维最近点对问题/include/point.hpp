#pragma once

#include <vector>
using namespace std;

// 点结构体
struct Point {
    double x, y;
};

// 计算两点见的欧几里得距离
double distance(const Point& a, const Point& b);

// 按 x 坐标排序
bool compareByX(const Point& a, const Point& b);

// 按 y 坐标排序
bool compareByY(const Point& a, const Point& b);

// 分治法寻找最近点
double closestPair(vector<Point>& points, int left, int right, vector<Point>& temp);