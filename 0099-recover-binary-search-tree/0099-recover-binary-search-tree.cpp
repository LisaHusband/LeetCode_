/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    // 用于存储需要交换的两个节点
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* prev = nullptr;

    void recoverTree(TreeNode* root) {
        // 使用中序遍历进行树的遍历
        inorderTraversal(root);

        // 交换这两个节点的值
        if (first && second) {
            swap(first->val, second->val);
        }
    }

    void inorderTraversal(TreeNode* node) {
        if (!node) return;

        // 递归左子树
        inorderTraversal(node->left);

        // 检查当前节点是否违反了BST的中序顺序
        if (prev && node->val < prev->val) {
            if (!first) {
                first = prev;  // 记录第一个错误节点
            }
            second = node;   // 记录第二个错误节点
        }

        // 更新前一个节点
        prev = node;

        // 递归右子树
        inorderTraversal(node->right);
    }
};


