#include "generateSubsets.hpp"
#include <iostream>
#include <string>
#include <vector>

void generateSubsetsRecursive(const vector<string>& set, int index, vector<string>& currentSubset, vector<vector<string>>& allSubsets)
{
    // 基线条件：如果到达集合末尾，保存当前子集并返回
    if (index == set.size()) {
        allSubsets.push_back(currentSubset);
        return;
    }

    // 选择1：不加入当前元素，直接递归到下一个元素
    generateSubsetsRecursive(set, index + 1, currentSubset, allSubsets);

    // 选择2：加入当前元素，再递归到下一个元素
    currentSubset.push_back(set[index]);
    generateSubsetsRecursive(set, index + 1, currentSubset, allSubsets);

    // 回溯：移除最后加入的元素（恢复状态）
    currentSubset.pop_back();
    /*
    每个递归分支都在一个"干净"的状态下开始
    一个分支的选择不会影响其他分支
    */
}

void generateSubsets(const vector<string>& set)
{
    vector<vector<string>> allSubsets; // 存储所有子集
    vector<string> currentSubset; // 当前子集

    // 调用递归函数
    generateSubsetsRecursive(set, 0, currentSubset, allSubsets);

    // 输出所有子集
    for (const auto& subset : allSubsets) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }
}

void generateSubsetsBin(const vector<string>& set)
{
    int n = set.size();
    int subsetCount = 1 << n; // 2^n
    vector<vector<string>> allSubsets;

    for (int i = 0; i < subsetCount; i++) {
        vector<string> subset;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset.push_back(set[j]);
            }
        }
        allSubsets.push_back(subset);
    }

    // 输出所有子集
    for (const auto& subset : allSubsets) {
        cout << "{";
        for (size_t i = 0; i < subset.size(); ++i) {
            cout << subset[i];
            if (i < subset.size() - 1)
                cout << ", ";
        }
        cout << "}" << endl;
    }
}