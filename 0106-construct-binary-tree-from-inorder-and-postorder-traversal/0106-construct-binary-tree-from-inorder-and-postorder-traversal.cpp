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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.empty() || postorder.empty()) return NULL;

        unordered_map<int, int> inorder_map; // 用于快速查找中序元素的位置
        for (int i = 0; i < inorder.size(); ++i) {
            inorder_map[inorder[i]] = i;
        }

        // 使用指针来遍历数组，而不是修改传入值
        auto postorder_ptr = postorder.rbegin(); // 后序遍历的逆向迭代器
        auto inorder_ptr = inorder.begin();

        stack<TreeNode*> stack;
        TreeNode* root = new TreeNode(*postorder_ptr); // 后序遍历最后一个元素是根
        stack.push(root);
        ++postorder_ptr;

        while (postorder_ptr != postorder.rend()) {
            int current_val = *postorder_ptr;
            TreeNode* node = stack.top();

            // 如果当前值在中序遍历中位于当前节点的右边，则为右子树
            if (inorder_map[current_val] > inorder_map[node->val]) {
                TreeNode* right_node = new TreeNode(current_val);
                node->right = right_node;
                stack.push(right_node);
            } else {
                // 否则处理左子树
                while (!stack.empty() && inorder_map[current_val] < inorder_map[stack.top()->val]) {
                    node = stack.top();
                    stack.pop();
                }
                TreeNode* left_node = new TreeNode(current_val);
                node->left = left_node;
                stack.push(left_node);
            }

            ++postorder_ptr;
        }

        return root;
    }
};