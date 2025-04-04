#include <iostream>
#include <utility>
#include <vector>

using namespace std;

/* 打印数组 */
void print_vector(vector<int> &nums) {
  for (int num : nums) {
    cout << num << " ";
  }

  cout << endl;
}

/*----------------------------- 方式一：排好序再划分 -------------------------------*/
int get_pivot_index(vector<int> &nums, int left, int right) {
  int i = left, j = right;
  while (i < j) {
    while (nums[j] >= nums[left] && i < j) {
      j--;
    }
    while (nums[i] <= nums[left] && i < j) {
      i++;
    }

    swap(nums[i], nums[j]);
  }

  swap(nums[left], nums[i]);

  return i;
}

/* 快速排序 */
void quick_sort(vector<int> &nums, int left, int right) {
  if (left > right) {
    return;
  }

  int pivot = get_pivot_index(nums, left, right);

  quick_sort(nums, left, pivot - 1);
  quick_sort(nums, pivot + 1, right);
}

/* 把数组划分两个不相交子集：|n1 - n2| 最小，|S1 - S2| 最大 */
vector<int> divide_nums_01(vector<int> &nums) {
  int mid = nums.size() / 2;
  vector<int> nums_02;
  for (int i = nums.size() - 1; i >= mid; i--) {
    nums_02.push_back(nums[i]);
  }

  nums.erase(nums.begin() + mid, nums.end());

  return nums_02;
}

/*----------------------------- 方式二：不排序划分 -------------------------------*/
/* 利用快速选择将前半部分调整为较小的一半 */
void quick_select(vector<int> &nums, int left, int right, int k) {
  if (left >= right)
    return;

  int pivot = nums[left];
  int i = left + 1, j = right;
  while (i <= j) {
    while (i <= j && nums[i] <= pivot)
      i++;
    while (i <= j && nums[j] > pivot)
      j--;
    if (i < j)
      swap(nums[i], nums[j]);
  }
  swap(nums[left], nums[j]); // j 是 pivot 最终位置

  int num = j - left + 1;
  if (num == k)
    return;
  else if (num < k)
    quick_select(nums, j + 1, right, k - num);
  else
    quick_select(nums, left, j - 1, k);
}

/* 划分数组为两个子集，使 |n1 - n2| 最小，|S1 - S2| 最大 */
vector<int> divide_nums_02(vector<int> &nums) {
  int n = nums.size();
  int k = n / 2;

  // 找前 k 小的元素放前面
  quick_select(nums, 0, n - 1, k);

  vector<int> subset_big(nums.begin() + k, nums.end()); // 后一半大的元素
  nums.erase(nums.begin() + k, nums.end());             // 保留前一半小的

  return subset_big;
}

/*----------------------------- 方式二：迭代实现 -------------------------------*/
vector<int> divide_nums_03(vector<int> &nums) {
  int n = nums.size();
  int target_index = n / 2;
  int left = 0, right = n - 1;

  // 快速选择算法，找到第n/2大的元素，并使左边都小于等于它，右边都大于等于它
  while (left < right) {
    // 以左边第一个元素为pivot
    int pivot = nums[left];
    int i = left, j = right;

    while (i < j) {
      while (i < j && nums[j] >= pivot)
        j--;
      nums[i] = nums[j];

      while (i < j && nums[i] <= pivot)
        i++;
      nums[j] = nums[i];
    }

    nums[i] = pivot; // 放置pivot

    if (i == target_index) {
      // 找到了分割点
      break;
    } else if (i < target_index) {
      // 继续在右半部分寻找
      left = i + 1;
    } else {
      // 继续在左半部分寻找
      right = i - 1;
    }
  }

  // 分割数组
  vector<int> nums_02(nums.begin() + target_index, nums.end());
  nums.resize(target_index);

  return nums_02;
}

void test_01() {
  vector<int> nums = {2,
                      1,
                      5,
                      3, 8, 6, 9, 4, 15, 10, 13};

  cout << "初始数组：";
  print_vector(nums);

  cout << "排好序的数组：";
  quick_sort(nums, 0, nums.size() - 1);
  print_vector(nums);

  vector<int> nums_02 = divide_nums_01(nums);
  cout << "n1: ";
  print_vector(nums);
  cout << "n2: ";
  print_vector(nums_02);
}

void test_02() {
  vector<int> nums = {2,
                      1,
                      5,
                      3, 8, 6, 9, 4, 15, 10};

  cout << "初始数组：";
  print_vector(nums);

  vector<int> nums_02 = divide_nums_02(nums);
  cout << "n1: ";
  print_vector(nums);
  cout << "n2: ";
  print_vector(nums_02);
}

void test_03() {
  vector<int> nums = {2,
                      1,
                      5,
                      3, 8, 6, 9, 4, 15, 10};

  cout << "初始数组：";
  print_vector(nums);

  vector<int> nums_02 = divide_nums_03(nums);
  cout << "n1: ";
  print_vector(nums);
  cout << "n2: ";
  print_vector(nums_02);
}

int main() {
  test_01();
  cout << endl;
  test_02();
  cout << endl;
  test_03();

  return 0;
}