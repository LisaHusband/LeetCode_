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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;  // 如果树为空，返回空结果

        queue<TreeNode*> q;  // 用队列来进行层序遍历
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();  // 当前层的节点个数
            vector<int> currentLevel;  // 当前层的节点值

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                currentLevel.push_back(node->val);  // 访问当前节点

                // 将当前节点的左右子节点加入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(currentLevel);  // 添加当前层的节点值到结果中
        }

        return result;
    }
};