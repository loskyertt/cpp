#pragma once

#include <vector>
using namespace std;

/* 合并左子数组和右子数组 */
void merge(vector<int>& nums, int left, int mid, int right);

/* 归并排序 */
void mergeSort(vector<int>& nums, int left, int right);