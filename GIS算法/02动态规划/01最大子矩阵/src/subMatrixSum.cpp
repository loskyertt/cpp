#include "subMatrixSum.hpp"
#include <climits>

int Solution::maxSubarraySum(std::vector<std::vector<int>>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    int rows = matrix.size();
    int cols = matrix[0].size();

    // 计算前缀和矩阵
    std::vector<std::vector<int>> prefixSum(rows + 1, std::vector<int>(cols + 1, 0));
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            prefixSum[i][j] = matrix[i - 1][j - 1] + prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
        }
    }

    int maxSum = INT_MIN;

    // 枚举所有子矩阵
    for (int top = 1; top <= rows; top++) {
        for (int bottom = top; bottom <= rows; bottom++) {
            for (int left = 1; left <= cols; left++) {
                for (int right = left; right <= cols; right++) {
                    // 计算当前子矩阵的和
                    int subSum = prefixSum[bottom][right]
                        - prefixSum[top - 1][right]
                        - prefixSum[bottom][left - 1]
                        + prefixSum[top - 1][left - 1];

                    maxSum = std::max(maxSum, subSum);
                }
            }
        }
    }

    return maxSum;
}
