#include "solution.hpp"
#include <iostream>

int main()
{
    // 示例: 矩阵维度序列
    vector<int> dimensions = { 30, 35, 15, 5, 10, 20, 25 };

    // 创建求解器实例
    MatrixChainMultiplication solver(dimensions);

    // 计算最小乘法次数
    int minMultiplications = solver.solve();

    // 输出结果
    cout << "矩阵维度序列: ";
    for (int dim : dimensions) {
        cout << dim << " ";
    }
    cout << endl;

    cout << "最小乘法次数: " << minMultiplications << endl;

    // 打印最优括号化方案
    solver.printOptimalParenthesization();

    // 打印DP表格（可选）
    solver.printDPTable();

    return 0;
}