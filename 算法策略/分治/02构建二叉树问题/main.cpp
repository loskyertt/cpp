#include "buidTree.hpp"
#include <iostream>

using namespace std;

// 构建二叉树的测试函数
void printTree(TreeNode* node)
{
    if (node == NULL)
        return;

    cout << node->val << " ";
    printTree(node->left);
    printTree(node->right);
}

int main()
{
    // 测试输入数据
    vector<int> preorder = { 3, 9, 20, 15, 7 };
    vector<int> inorder = { 9, 3, 15, 20, 7 };

    TreeNode* root = buildTree(preorder, inorder);

    cout << "二叉树：" << endl;
    printTree(root);
    return 0;
}