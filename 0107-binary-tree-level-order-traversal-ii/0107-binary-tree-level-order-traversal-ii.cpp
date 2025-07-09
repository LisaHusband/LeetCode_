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
//  BFS变种
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
       vector<vector<int>> result;
        if (!root) return result;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int level_size = q.size();  // 当前层的节点个数
            vector<int> level_values;
            
            // 处理当前层的所有节点
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();
                level_values.push_back(node->val);
                
                // 将子节点加入队列
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            
            result.push_back(level_values);
        }
        
        // 反转结果，得到自底向上的顺序
        reverse(result.begin(), result.end());
        
        return result;
    }
};