#include "subsetSumI.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> nums = { 3, 4, 5 };
    int target = 9;
    vector<vector<int>> res;
    res = subsetSumI(nums, target);
    for (vector<int> res_nums : res) {
        for (int nums : res_nums) {
            cout << nums;
        }
        cout << endl;
    }

    return 0;
}