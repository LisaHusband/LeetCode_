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
    int maxDepth(TreeNode* root) {
        // 递归终止条件：空树的深度是0
        if (!root) {
            return 0;
        }

        // 递归计算左子树和右子树的最大深度
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // 当前节点的深度 = max(左子树深度, 右子树深度) + 1
        return max(leftDepth, rightDepth) + 1;
    }
};