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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty()) return NULL;

        unordered_map<int, int> inorder_map;
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;  // 将中序遍历的元素位置记录下来
        }

        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push(root);
        int preorder_index = 1;

        for (int i = 0; i < preorder.size() - 1; ++i) {
            int current_val = preorder[preorder_index];
            TreeNode* node = stack.top();
            
            // 根据当前值与中序位置来决定是构建左子树还是右子树
            if (inorder_map[current_val] < inorder_map[node->val]) {
                // 如果当前值在中序遍历中在当前节点的左侧，构建左子树
                TreeNode* left_node = new TreeNode(current_val);
                node->left = left_node;
                stack.push(left_node);
            } else {
                // 否则，构建右子树
                while (!stack.empty() && inorder_map[current_val] > inorder_map[stack.top()->val]) {
                    node = stack.top();
                    stack.pop();
                }
                TreeNode* right_node = new TreeNode(current_val);
                node->right = right_node;
                stack.push(right_node);
            }
            preorder_index++;
        }
        return root;
    }
};