#pragma once

#include <vector>
using namespace std;

/*回溯算法：子集和I*/
void backtrack(vector<int>& state, int target, vector<int>& choices, int start, vector<vector<int>>& res);

/*求解子集I*/
vector<vector<int>> subsetSumI(vector<int>& nums, int target);