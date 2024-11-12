#include "generatePermutations.hpp"
#include <utility>

void generatePermutations(vector<int>& nums, int start, vector<vector<int>>& result)
{
    if (start == nums.size() - 1) { // 基本情况：最后一个元素
        result.push_back(nums); // 将当前排列加入结果
        return;
    }

    for (int i = start; i < nums.size(); i++) {
        swap(nums[start], nums[i]); // 固定当前元素
        generatePermutations(nums, start + 1, result); // 对剩下的元素递归生成全排列
        swap(nums[start], nums[i]); // 回溯，恢复原状
    }
}