#include "huffman.hpp"
#include <iostream>

using std::cout;

// private:
/* 统计字符频率 */
unordered_map<char, unsigned> Huffman::count_freq(const string &text) {
  unordered_map<char, unsigned> freq_map;
  for (char c : text) {
    freq_map[c]++;
  }

  return freq_map;
}

// public:
/* 构造函数 */
Huffman::Huffman(const string &text) {
  unordered_map<char, unsigned> freq_map = count_freq(text);

  // 将叶节点放入优先队列
  for (auto [key, value] : freq_map) {
    min_heap.push(new TreeNode(key, value));
  }
}

/* 创建霍夫曼树 */
TreeNode *Huffman::build_Huffman_tree() {
  // 处理只有一个字符的特殊情况
  if (min_heap.size() == 1) {
    auto left = min_heap.top();
    min_heap.pop();
    TreeNode *root = new TreeNode('\0', left->freq);
    root->left = left;

    return root;
  }

  // 合并节点直到只剩根节点
  while (min_heap.size() > 1) {
    auto left = min_heap.top();
    min_heap.pop();
    auto right = min_heap.top();
    min_heap.pop();

    // 创建内部节点，合并两个最小节点
    TreeNode *new_node = new TreeNode('\0', left->freq + right->freq);
    new_node->left = left;
    new_node->right = right;

    min_heap.push(new_node);
  }

  return min_heap.top();
}

/* 生成霍夫曼编码 */
void Huffman::generate_codes(TreeNode *root, string code, unordered_map<char, string> &huffman_codes) {
  if (!root) {
    return;
  }

  // 只有叶子节点才存储编码
  if (!root->left && !root->right) {
    huffman_codes[root->val] = code;
  }

  generate_codes(root->left, code + "0", huffman_codes);
  generate_codes(root->right, code + "1", huffman_codes);
}

/* 中序遍历 */
void Huffman::in_order(TreeNode *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}