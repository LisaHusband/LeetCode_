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
// BFS变种
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true;  // 标志位，控制当前层遍历方向

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level;
            
            // 逐层遍历
            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level.push_back(node->val);

                // 将左右子节点加入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            // 如果当前层的遍历方向是从右往左，反转当前层
            if (!leftToRight) {
                reverse(level.begin(), level.end());
            }

            // 添加当前层到结果中
            result.push_back(level);

            // 改变下一层的遍历方向
            leftToRight = !leftToRight;
        }

        return result;
    }
};