#pragma once

#include <string>
#include <vector>

using namespace std;

/* 方法一：递归实现 */
void generateSubsetsRecursive(const vector<string>& set, int index, vector<string>& currentSubset, vector<vector<string>>& allSubsets);

void generateSubsets(const vector<string>& set);

/* 方法二：位移实现 */
void generateSubsetsBin(const vector<string>& set);