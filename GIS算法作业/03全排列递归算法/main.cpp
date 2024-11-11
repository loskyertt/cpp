#include <iostream>
#include <vector>
using namespace std;

// 递归函数生成全排列
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

int main()
{
    vector<int> nums = { 1, 2, 3 }; // 要生成全排列的元素
    vector<vector<int>> result;

    generatePermutations(nums, 0, result);

    // 输出结果
    cout << "全排列结果:" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
