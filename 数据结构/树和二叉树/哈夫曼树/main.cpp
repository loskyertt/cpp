#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

// 哈夫曼树节点结构
struct HuffmanNode {
  char data;     // 字符（仅叶子节点有效）
  unsigned freq; // 频率
  HuffmanNode *left, *right;

  HuffmanNode(char data, unsigned freq)
      : data(data), freq(freq), left(nullptr), right(nullptr) {}
};

// 用于优先队列的比较器（最小堆）
struct Compare {
  bool operator()(HuffmanNode *l, HuffmanNode *r) { return l->freq > r->freq; }
};

// 统计字符频率
map<char, unsigned> countFrequency(const string &text) {
  map<char, unsigned> freqMap;
  for (char c : text) {
    freqMap[c]++; // 等价于 freqMap[c] = freqMap[c] + 1;
  }
  return freqMap;
}

// 构建哈夫曼树
HuffmanNode *buildHuffmanTree(const map<char, unsigned> &freqMap) {
  priority_queue<HuffmanNode *, vector<HuffmanNode *>, Compare> minHeap;

  // 创建叶子节点并加入优先队列
  for (auto &pair : freqMap) {
    minHeap.push(new HuffmanNode(pair.first, pair.second));
  }

  // 处理只有一个字符的特殊情况
  if (minHeap.size() == 1) {
    auto left = minHeap.top();
    minHeap.pop();
    HuffmanNode *root = new HuffmanNode('\0', left->freq);
    root->left = left;
    return root;
  }

  // 合并节点直到只剩根节点
  while (minHeap.size() > 1) {
    HuffmanNode *left = minHeap.top();
    minHeap.pop();
    HuffmanNode *right = minHeap.top();
    minHeap.pop();

    // 创建内部节点，合并两个最小节点
    HuffmanNode *newNode = new HuffmanNode('\0', left->freq + right->freq);
    newNode->left = left;
    newNode->right = right;
    minHeap.push(newNode);
  }

  return minHeap.top();
}

// 生成哈夫曼编码
void generateCodes(HuffmanNode *root, string code,
                   map<char, string> &huffmanCodes) {
  if (!root)
    return;

  // 叶子节点存储编码
  if (!root->left && !root->right) {
    huffmanCodes[root->data] = code;
  }

  generateCodes(root->left, code + "0", huffmanCodes);
  generateCodes(root->right, code + "1", huffmanCodes);
}

// 释放哈夫曼树内存
void deleteTree(HuffmanNode *root) {
  if (!root)
    return;
  deleteTree(root->left);
  deleteTree(root->right);
  delete root;
}

int main() {
  string text = "ABRACADABRA";
  map<char, unsigned> freqMap = countFrequency(text);

  cout << "各个字符频率：" << endl;
  for (auto kv : freqMap) {
    cout << kv.first << ": " << kv.second << endl;
  }
  cout << endl;

  // 构建哈夫曼树
  HuffmanNode *root = buildHuffmanTree(freqMap);

  // 生成并打印哈夫曼编码
  map<char, string> huffmanCodes;
  generateCodes(root, "", huffmanCodes);
  cout << "Huffman Codes:\n";
  for (auto &pair : huffmanCodes) {
    cout << "'" << pair.first << "' : " << pair.second << endl;
  }

  // 释放内存
  deleteTree(root);

  return 0;
}