#include "permutations.hpp"
#include <iostream>

void test01()
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
}

// 测试函数
int main()
{
    test01();
    // test02();

    return 0;
}