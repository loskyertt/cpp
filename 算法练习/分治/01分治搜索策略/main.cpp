#include "binarySearch.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums = { 1, 2, 3, 4, 5, 6 };
    int result = binarySearch(nums, 2);
    cout << "目标元素索引为：" << result << endl;

    return 0;
}