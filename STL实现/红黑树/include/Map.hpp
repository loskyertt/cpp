#pragma once

#include <cassert>

struct Node {
    Node* ppnext; // 父节点
    Node* left; // 左子节点
    Node* right; // 右子节点
    int value; // 数据
};

struct set {
    Node* root = nullptr;

    Node* find(int value)
    {
        Node* current = root;
        while (current != nullptr) {
            if (value < current->value) {
                current = current->left;
            } else if (value > current->value) {
                current = current->right;
            } else { // value == current->value
                return current; // 找到值，返回当前节点
            }
        }
        return nullptr; // 没有找到值，返回nullptr
    }

    bool insert(int value)
    {
        Node* node = new Node;
        node->value = value;
        node->left = nullptr;
        node->right = nullptr;

        Node** ppnext = &root;
        while (*ppnext == nullptr) {
            if (value < (*ppnext)->value) {
                ppnext = &(*ppnext)->left;
                continue;
            }
            if (value > (*ppnext)->value) {
                ppnext = &(*ppnext)->right;
                continue;
            }
            return false;
        }

        *ppnext = node;

        return true;
    }
};