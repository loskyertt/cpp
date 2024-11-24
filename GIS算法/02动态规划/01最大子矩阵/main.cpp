#include "subMatrixSum.hpp"
#include <iostream>

int main()
{
    Solution solution;
    std::vector<std::vector<int>> matrix = { { 1, 2, 3 },
        { 4, -2, 6 },
        { 7, 8, -20 } };
    int result = solution.maxSubarraySum(matrix);

    std::cout << result << std::endl;

    return 0;
}