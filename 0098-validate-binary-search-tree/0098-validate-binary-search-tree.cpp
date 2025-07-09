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
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        // BFS遍历时存储每个节点的值的有效区间 [min, max]
        queue<pair<TreeNode*, pair<long long, long long>>> q;
        q.push({root, {LONG_MIN, LONG_MAX}});  // 初始范围为 [-INF, INF]

        while (!q.empty()) {
            auto [node, range] = q.front();
            q.pop();

            long long minVal = range.first;
            long long maxVal = range.second;

            // 判断当前节点是否符合范围
            if (node->val <= minVal || node->val >= maxVal) {
                return false;
            }

            // 如果有左子树，更新其有效范围 [min, node->val]
            if (node->left) {
                q.push({node->left, {minVal, node->val}});
            }

            // 如果有右子树，更新其有效范围 [node->val, max]
            if (node->right) {
                q.push({node->right, {node->val, maxVal}});
            }
        }

        return true;
    }
};