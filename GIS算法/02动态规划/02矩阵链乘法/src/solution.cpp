#include "solution.hpp"
#include <iostream>

void MatrixChainMultiplication::printParenthesis(int i, int j, vector<string>& matrixNames)
{
    if (i == j) {
        cout << matrixNames[i];
        return;
    }
    cout << "(";
    printParenthesis(i, splits[i][j], matrixNames);
    printParenthesis(splits[i][j] + 1, j, matrixNames);
    cout << ")";
}

int MatrixChainMultiplication::solve()
{
    int n = dimensions.size() - 1;

    // l是当前计算的链长度
    for (int l = 2; l <= n; l++) {
        // i是子链的起点
        for (int i = 0; i <= n - l; i++) {
            int j = i + l - 1; // j是子链的终点

            // 尝试所有可能的切分点
            for (int k = i; k < j; k++) {
                // 计算当前切分方案的代价
                int cost = dp[i][k] + dp[k + 1][j] + dimensions[i] * dimensions[k + 1] * dimensions[j + 1];

                // 更新最小代价和最优切分点
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                    splits[i][j] = k;
                }
            }
        }
    }

    return dp[0][n - 1];
}

void MatrixChainMultiplication::printDPTable()
{
    cout << "\nDP Table:\n";
    for (const auto& row : dp) {
        for (int val : row) {
            if (val == INT_MAX)
                cout << "INF ";
            else
                cout << val << " ";
        }
        cout << endl;
    }
}

void MatrixChainMultiplication::printOptimalParenthesization()
{
    vector<string> matrixNames;
    for (int i = 0; i < dimensions.size() - 1; i++) {
        matrixNames.push_back("A" + to_string(i + 1));
    }

    cout << "最优括号化方案: ";
    printParenthesis(0, dimensions.size() - 2, matrixNames);
    cout << endl;
}