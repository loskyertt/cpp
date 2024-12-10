#include "tree.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<int> path;
vector<vector<int>> res;

void delete_tree(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    delete_tree(root->left);
    delete_tree(root->right);
    delete root;
}

void pre_order(TreeNode* root)
{
    if (root == nullptr) {
        return;
    }
    // 尝试
    path.push_back(root->val);
    if (root->val == 7) {
        // 记录解
        res.push_back(path);
    }
    pre_order(root->left);
    pre_order(root->right);

    // 回退
    path.pop_back();
}

void print_val()
{
    // for (TreeNode* node : res) {
    //     if (node->left != nullptr) {
    //         cout << "左节点的值：" << node->left->val << endl;
    //     } else {
    //         cout << "左节点的值：null" << endl;
    //     }
    //     if (node->right != nullptr) {
    //         cout << "右节点的值：" << node->right->val << endl;
    //     } else {
    //         cout << "右节点的值：null" << endl;
    //     }
    // }

    for (vector<int> list : res) {
        for (int val : list) {
            cout << val << " ";
        }
        cout << endl;
    }
}
