#pragma once

#include <vector>
using namespace std;

/*回溯算法：全排列 l*/
void backtrack(vector<int>& state, const vector<int>& choices, vector<bool>& selected, vector<vector<int>>& res);

/*全排列*/
vector<vector<int>> permutations(vector<int> nums);