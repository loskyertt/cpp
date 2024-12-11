#pragma once

#include <vector>

class Solution {
public:
    /* 方法一：前后缀分解 */
    int trap_pre_suf(std::vector<int>& height);

    /* 方法二：相向双指针 */
    int trap_ptr(std::vector<int>& height);
};