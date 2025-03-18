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

/* 调整堆，自顶向下 */
void sift_down(vector<int> &heap, int i) {
  while (true) {
    int left_index = 2 * i + 1;
    int right_index = 2 * i + 2;
    int min_index = i;

    if (left_index < heap.size() && heap[left_index] < heap[min_index]) {
      min_index = left_index;
    }
    if (right_index < heap.size() && heap[right_index] < heap[min_index]) {
      min_index = right_index;
    }

    if (min_index == i) {
      break;
    }

    swap(heap[i], heap[min_index]);
    i = min_index;
  }
}

/* top-k */
vector<int> top_k(vector<int> nums, int k) {
  // 构造小顶堆
  vector<int> nums_k;

  for (int i = 0; i < k; i++) {
    nums_k.push_back(nums[i]);
  }

  // 完全堆化 - 从最后一个非叶节点开始向上调整， k/2-1 其实就是 (k-1-1)/2
  for (int i = k / 2 - 1; i >= 0; i--) {
    sift_down(nums_k, i);
  }

  for (int j = k; j < nums.size(); j++) {
    if (nums[j] > nums_k[0]) {
      nums_k[0] = nums[j];
      sift_down(nums_k, 0);
    }
  }

  return nums_k;
}

void test() {
  vector<int> nums = {2, 7, 8, 11, 10,
                      5, 6, 10, 11, 4, 9};

  int k = 6;
  vector<int> nums_k = top_k(nums, k);

  cout << "前 " << k << " 大个数为：";
  print_vector(nums_k);
}

int main() {
  test();

  return 0;
}