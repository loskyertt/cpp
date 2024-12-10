#include "merge_sort.hpp"
#include <iostream>
#include <vector>

int main()
{
    vector<int> nums = { 2, 1, 4, 6, 10, 4, 5, 7 };
    mergeSort(nums, 0, 7);

    for (int num : nums) {
        cout << num << " ";
    }

    return 0;
}