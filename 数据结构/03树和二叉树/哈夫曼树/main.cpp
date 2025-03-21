#include "huffman.hpp"
#include <iostream>

using std::cout;
using std::endl;

void test() {
  string text = "ABRACADABRA";

  Huffman h(text);
  TreeNode *huffman_tree = h.build_Huffman_tree();
  h.in_order(huffman_tree);

  cout << endl;

  unordered_map<char, string> huffman_codes;
  h.generate_codes(huffman_tree, "", huffman_codes);

  cout << "Huffman Codes:" << endl;
  for (auto pair : huffman_codes) {
    cout << "'" << pair.first << "' : " << pair.second << endl;
  }
}

int main() {
  test();

  return 0;
}