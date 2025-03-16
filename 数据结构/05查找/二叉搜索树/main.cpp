#include <cstdio>
#include <iostream>
#include <stdexcept>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left, *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* 中序遍历：对二叉搜索树来说，就是从小到大的遍历 */
void in_order(TreeNode *root) {
  if (!root) {
    return;
  }

  in_order(root->left);
  cout << root->val << " ";
  in_order(root->right);
}

/* 查找操作：迭代实现 */
bool find_val_iteration(TreeNode *root, int val) {
  if (!root) {
    return false;
  }

  TreeNode *curr = root;
  while (curr) {
    if (curr->val < val) {
      curr = curr->right;
    } else if (curr->val > val) {
      curr = curr->left;
    } else {
      return true;
    }
  }

  return false;
}

/* 查找操作：递归实现 */
bool find_val_recursion(TreeNode *root, int val) {
  if (root == nullptr) {
    return false;
  }

  if (root->val < val) {
    return find_val_recursion(root->right, val);
  } else if (root->val > val) {
    return find_val_recursion(root->left, val);
  } else {
    return true;
  }
}

/* 插入操作：迭代插入 */
void insert_iteration(TreeNode *root, int val) {
  TreeNode *new_node = new TreeNode(val);

  if (!root) {
    root = new_node;
    return;
  }

  // 需要定义前驱节点，记录前一个节点的信息
  TreeNode *prev = nullptr;
  // curr 节点为一直往左走或者右走，直到走到空
  TreeNode *curr = root;

  while (curr) {
    // 找到重复节点，直接返回
    if (curr->val == val) {
      return;
    }
    prev = curr;

    // 插入位置在 curr 的右子树中
    if (curr->val < val) {
      curr = curr->right;
    } else {
      // 插入位置在 curr 的左子树中
      curr = curr->left;
    }
  }

  if (prev->val < val) {
    prev->right = new_node;
  } else {
    prev->left = new_node;
  }
}

/* 插入节点：递归实现 */
TreeNode *insert_recursion(TreeNode *root, int val) {
  if (!root) {
    root = new TreeNode(val);
    return root;
  }

  if (root->val < val) {
    root->right = insert_recursion(root->right, val);
  } else if (root->val > val) {
    root->left = insert_recursion(root->left, val);
  } else {
    return root;
  }

  return root;
}

/* 删除节点：迭代实现 */
void remove_iteration(TreeNode *root, int num) {
  // 若树为空，直接提前返回
  if (root == nullptr)
    throw out_of_range("树为空！");
  TreeNode *cur = root, *pre = nullptr;
  // 循环查找，越过叶节点后跳出
  while (cur != nullptr) {
    // 找到待删除节点，跳出循环
    if (cur->val == num)
      break;
    pre = cur;
    // 待删除节点在 cur 的右子树中
    if (cur->val < num)
      cur = cur->right;
    // 待删除节点在 cur 的左子树中
    else
      cur = cur->left;
  }

  // 若无待删除节点，则直接返回
  if (cur == nullptr)
    throw out_of_range("没有这个节点！");

  // 子节点数量 = 0 or 1
  if (cur->left == nullptr || cur->right == nullptr) {
    // 当子节点数量 = 0 / 1 时， child = nullptr / 该子节点
    TreeNode *child = cur->left != nullptr ? cur->left : cur->right;
    // 删除节点 cur
    if (cur != root) {
      if (pre->left == cur)
        pre->left = child;
      else
        pre->right = child;
    } else {
      // 若删除节点为根节点，则重新指定根节点
      root = child;
    }
    // 释放内存
    delete cur;
  }
  // 子节点数量 = 2
  else {
    // 获取右子树的最小节点（一直往右子树的左边走即可）
    TreeNode *tmp = cur->right;
    while (tmp->left != nullptr) {
      tmp = tmp->left;
    }
    int tmpVal = tmp->val;
    // 这里不用看成是递归删除，因为删除的这个 tmp 节点一定是度为 0 或者 1 的节点
    remove_iteration(cur, tmpVal);
    // 用 tmp 的数值域覆盖 cur 的数值域即可
    cur->val = tmpVal;
  }
}

/* 递归操作实现 */
TreeNode *remove_resursion(TreeNode *root, int target) {
  if (!root) {
    throw out_of_range("树为空！");
  }

  if (root->val < target) {
    // 左边的 roo->right 相当于迭代实现中的 prev 前驱节点
    root->right = remove_resursion(root->right, target);
  } else if (root->val > target) {
    root->left = remove_resursion(root->left, target);
  } else {
    if (root->left == nullptr || root->right == nullptr) {
      TreeNode *child = root->left != nullptr ? root->left : root->right;
      if (!child) {
        delete root;
        return nullptr;
      } else {
        delete root;
        root = child;
      }
    } else {
      TreeNode *tmp = root->right;
      while (tmp->left) {
        tmp = tmp->left;
      }
      int tmp_val = tmp->val;
      root->right = remove_resursion(root->right, tmp_val);
      root->val = tmp_val;
    }
  }

  return root;
}

void test() {
  TreeNode *root = new TreeNode(8);
  root->left = new TreeNode(4);
  root->right = new TreeNode(12);
  root->left->left = new TreeNode(2);
  root->left->right = new TreeNode(6);
  root->right->left = new TreeNode(10);
  // root->left->right->left = new TreeNode(5);

  cout << "初始二叉搜索树：";
  in_order(root);

  cout << endl;

  // 迭代操作实现
  // cout << "迭代操作实现：" << endl;
  // insert_iteration(root, 7);
  // cout << "插入新节点后的二叉搜索树：";
  // in_order(root);

  // cout << endl;

  // cout << "删除节点后的二叉树：";
  // remove_iteration(root, 4);
  // in_order(root);

  // 递归操作实现
  cout << "递归操作实现：" << endl;
  insert_recursion(root, 7);
  cout << "插入新节点后的二叉搜索树：";
  in_order(root);

  cout << endl;

  cout << "删除节点后的二叉树：";
  remove_resursion(root, 4);
  in_order(root);
}

int main() {
  test();

  return 0;
}