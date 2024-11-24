#pragma once
#include <vector>

/* 动态规划实现 */
class Solution {
public:
    int maxSubarraySum(std::vector<std::vector<int>>& matrix);
};

// class Solution {
// public:
//     int maxSubarraySum(std::vector<std::vector<int>>& matrix)
//     {
//         if (matrix.empty() || matrix[0].empty())
//             return 0;

//         int rows = matrix.size();
//         int cols = matrix[0].size();
//         int maxSum = INT_MIN;

//         // 尝试所有可能的子矩阵
//         for (int top = 0; top < rows; top++) {
//             // 压缩列的临时数组
//             std::vector<int> temp(cols, 0);

//             for (int bottom = top; bottom < rows; bottom++) {
//                 // 累加当前行到临时数组
//                 for (int col = 0; col < cols; col++) {
//                     temp[col] += matrix[bottom][col];
//                 }

//                 // 对临时数组应用一维最大子数组和算法
//                 int currentSum = kadane(temp);
//                 maxSum = std::max(maxSum, currentSum);
//             }
//         }

//         return maxSum;
//     }

// private:
//     // 一维Kadane算法求最大子数组和
//     int kadane(std::vector<int>& arr)
//     {
//         int maxSoFar = arr[0];
//         int currentMax = arr[0];

//         for (int i = 1; i < arr.size(); i++) {
//             currentMax = std::max(arr[i], currentMax + arr[i]);
//             maxSoFar = std::max(maxSoFar, currentMax);
//         }

//         return maxSoFar;
//     }
// };