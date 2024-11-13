#include "permutations.hpp"
#include <iostream>

// 测试函数
int main()
{
    vector<int> nums = { 1, 2, 3 }; // 输入数据
    vector<vector<int>> result = permutations(nums);

    cout << "全排列结果：" << endl;
    for (const auto& perm : result) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}