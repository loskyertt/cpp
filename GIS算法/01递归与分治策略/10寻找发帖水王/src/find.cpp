#include "find.hpp"

int find(vector<int>& id, int n)
{
    int sw = 0; // 候选水王
    int count = 0; // 计数器

    // 第一阶段：寻找候选值
    for (int i = 0; i < n; i++) {
        if (count == 0) {
            sw = id[i];
            count = 1;
        } else {
            if (sw == id[i]) {
                count++;
            } else {
                count--;
            }
        }
    }

    // 第二阶段：验证候选值是否真的为水王
    count = 0;
    for (int i = 0; i < n; i++) {
        if (id[i] == sw) {
            count++;
        }
    }

    if (count > n / 2) {
        return sw; // 如果候选值的出现次数超过一半，返回水王
    } else {
        return -1; // 否则返回-1表示没有水王
    }
}