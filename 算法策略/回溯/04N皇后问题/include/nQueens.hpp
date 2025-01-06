#pragma once

#include <string>
#include <vector>
using namespace std;

/*回溯算法：n 皇后*/
void backtrack(int row, int n, vector<vector<string>>& state, vector<vector<vector<string>>>& res, vector<bool>& cols, vector<bool>& diags1, vector<bool>& diags2);

/*求解 N 皇后*/
vector<vector<vector<string>>> nQueens(int n);
