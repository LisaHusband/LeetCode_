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
            inorder_map[inorder[i]] = i;  // Store the index of each element in inorder
        }

        // Create pointers to iterate over the preorder and inorder arrays
        auto preorder_ptr = preorder.begin();
        auto inorder_ptr = inorder.begin();

        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(*preorder_ptr);
        stack.push(root);
        ++preorder_ptr;

        while (preorder_ptr != preorder.end()) {
            int current_val = *preorder_ptr;
            TreeNode* node = stack.top();

            // Decide if the current value should be part of the left or right subtree
            if (inorder_map[current_val] < inorder_map[node->val]) {
                // Left child
                TreeNode* left_node = new TreeNode(current_val);
                node->left = left_node;
                stack.push(left_node);
            } else {
                // Right child
                while (!stack.empty() && inorder_map[current_val] > inorder_map[stack.top()->val]) {
                    node = stack.top();
                    stack.pop();
                }
                TreeNode* right_node = new TreeNode(current_val);
                node->right = right_node;
                stack.push(right_node);
            }

            ++preorder_ptr;
        }

        return root;
    }
};