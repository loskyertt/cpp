#pragma once

#include <functional>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using std::greater;
using std::priority_queue;
using std::string;
using std::unordered_map;
using std::vector;

/* 霍夫曼树节点结构 */
struct TreeNode {
  char val;      // 字符（仅叶子节点有效）
  unsigned freq; // 频率
  TreeNode *left, *right;
  TreeNode(char x, unsigned y) : val(x), freq(y), left(nullptr), right(nullptr) {}
};

/* 用于小顶堆的比较器 */
struct Compare {
  bool operator()(TreeNode *l, TreeNode *r) { return l->freq > r->freq; }
};

class Huffman {
  /* 存放叶节点的小顶堆 */
  priority_queue<TreeNode *, vector<TreeNode *>, Compare> min_heap;

  /* 统计字符频率 */
  unordered_map<char, unsigned> count_freq(const string &text);

public:
  /* 构造函数 */
  Huffman(const string &text);

  /* 创建霍夫曼树 */
  TreeNode *build_Huffman_tree();

  /* 生成霍夫曼编码 */
  void generate_codes(TreeNode *root, string code, unordered_map<char, string> &huffman_codes);

  /* 中序遍历 */
  void in_order(TreeNode *root);
};