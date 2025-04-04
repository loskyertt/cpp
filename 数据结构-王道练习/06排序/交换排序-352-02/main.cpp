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

/* 自顶向下堆化：大顶堆 */
void sift_down(vector<int> &heap, int parent, int size) {
  while (true) {
    // 左孩子
    int left = parent * 2 + 1;
    // 右孩子
    int right = parent * 2 + 2;
    int max_index = parent;
    if (left < size && heap[left] > heap[max_index]) {
      max_index = left;
    }
    if (right < size && heap[right] > heap[max_index]) {
      max_index = right;
    }
    if (max_index == parent) {
      break;
    }
    swap(heap[parent], heap[max_index]);
    parent = max_index;
  }
}

/* 找到数组中第 k 小的元素 */
int get_smallest_k(vector<int> &nums, int k) {
  // 先把前 k 个元素放到 max_heap 中
  vector<int> max_heap(nums.begin(), nums.begin() + k);

  // 堆化 max_heap
  for (int i = (k - 2) / 2; i >= 0; i--) {
    sift_down(max_heap, i, k);
  }

  for (int j = k; j < nums.size(); j++) {
    if (nums[j] < max_heap[0]) {
      max_heap[0] = nums[j];
      sift_down(max_heap, 0, k);
    }
  }

  return max_heap[0];
}

void test() {
  vector<int> nums = {1, 5, 3, 2, 9, 8, 6, 7};
  int k = 4;

  int res = get_smallest_k(nums, k);
  cout << "第 " << k << " 小的元素：" << res << endl;
}

int main() {
  test();

  return 0;
}