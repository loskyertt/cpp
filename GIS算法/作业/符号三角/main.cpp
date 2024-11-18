#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

// 检查符号三角形是否满足条件
bool isValidTriangle(const vector<int>& row)
{
    int plusCount = 0, minusCount = 0;
    for (int val : row) {
        if (val == 1)
            plusCount++;
        else
            minusCount++;
    }
    return plusCount == minusCount;
}

// 打印完整的符号三角形
void printTriangle(const vector<vector<int>>& triangle)
{
    for (const auto& row : triangle) {
        for (int val : row) {
            cout << (val == 1 ? "+" : "-") << " ";
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
}

// 递归生成符号三角形
void generateTriangles(vector<vector<int>>& triangles, vector<int>& currentRow, int n, int index)
{
    if (index == n) { // 如果第一行已填满
        vector<int> row = currentRow;
        vector<vector<int>> triangle = { row };
        while (row.size() > 1) { // 生成完整的符号三角形
            vector<int> nextRow;
            for (size_t i = 0; i < row.size() - 1; i++) {
                nextRow.push_back((row[i] == row[i + 1]) ? 1 : -1);
            }
            triangle.push_back(nextRow);
            row = nextRow;
        }
        if (isValidTriangle(currentRow)) {
            triangles.push_back(currentRow);
            printTriangle(triangle); // 打印每个符合条件的三角形
        }
        return;
    }
    // 填写当前行的符号（1代表"+"，-1代表"-"）
    currentRow[index] = 1;
    generateTriangles(triangles, currentRow, n, index + 1);
    currentRow[index] = -1;
    generateTriangles(triangles, currentRow, n, index + 1);
}

int main()
{
    int n;
    cout << "请输入第一行的符号数目 n: ";
    cin >> n;

    vector<vector<int>> triangles;
    vector<int> currentRow(n);
    cout << "所有符号三角形如下：" << endl;
    generateTriangles(triangles, currentRow, n, 0);

    cout << "符号三角形的总数为: " << triangles.size() << endl;

    return 0;
}
