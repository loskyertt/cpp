#pragma once

#include <vector>
using namespace std;

/*移动一个圆盘*/
void move(vector<int>& src, vector<int>& tar);

/*求解汉诺塔问题 f(i)*/
void dfs(int i, vector<int>& src, vector<int>& buf, vector<int>& tar);

/*求解汉诺塔问题*/
void solveHanota(vector<int>& A, vector<int>& B, vector<int>& C);