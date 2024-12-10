#include "minPath.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<vector<int>> grid = {
        { 1, 3, 1 },
        { 1, 5, 1 },
        { 4, 2, 1 }
    };
    vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), -1));

    // int min_path = minPathSumDFS(grid, 2, 2);
    // int min_path = minPathSumDFSMem(grid, mem, 2, 2);
    int min_path = minPathSumDP(grid);

    cout << "最小路径为：" << min_path << endl;

    return 0;
}