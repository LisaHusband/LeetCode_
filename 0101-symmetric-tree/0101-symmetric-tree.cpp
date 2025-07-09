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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;  // 空树是对称的

        queue<TreeNode*> q;
        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            TreeNode* leftNode = q.front(); q.pop();
            TreeNode* rightNode = q.front(); q.pop();

            // 如果左右节点都为空，继续
            if (!leftNode && !rightNode) continue;
            
            // 如果只有一个为空，或者两个节点的值不相同，则不是对称的
            if (!leftNode || !rightNode || leftNode->val != rightNode->val) {
                return false;
            }

            // 将子节点按镜像的方式加入队列
            q.push(leftNode->left);
            q.push(rightNode->right);
            q.push(leftNode->right);
            q.push(rightNode->left);
        }

        return true;
    }
};