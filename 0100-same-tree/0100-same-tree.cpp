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
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 如果两棵树都为空，返回 true
        if (!p && !q) return true;

        // 如果一棵树为空，另一棵树不为空，返回 false
        if (!p || !q) return false;

        // 如果当前节点的值不同，返回 false
        if (p->val != q->val) return false;

        // 递归检查左子树和右子树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};