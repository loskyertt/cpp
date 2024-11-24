#pragma once

#include <climits>
#include <string>
#include <vector>
using namespace std;

class MatrixChainMultiplication {
private:
    vector<vector<int>> dp; // 存储最小乘法次数
    vector<vector<int>> splits; // 存储最优切分点
    vector<int> dimensions; // 存储矩阵维度

    // 递归打印最优括号化方案
    void printParenthesis(int i, int j, vector<string>& matrixNames);

public:
    MatrixChainMultiplication(const vector<int>& dims)
        : dimensions(dims)
    {
        int n = dims.size() - 1; // 矩阵个数
        dp.resize(n, vector<int>(n, INT_MAX));
        splits.resize(n, vector<int>(n, 0));

        // 初始化对角线
        for (int i = 0; i < n; i++) {
            dp[i][i] = 0;
        }
    }

    // 计算最小乘法次数
    int solve();

    // 打印 dp 表格（用于调试）
    void printDPTable();

    // 打印最优括号化方案
    void printOptimalParenthesization();
};