#include "generatePermutations.hpp"
#include <iostream>
using namespace std;

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
