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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) {
            return {};
        }
        return generate(1, n);
    }

    vector<TreeNode*> generate(int start, int end) {
        if (start > end) {
            return {nullptr}; // 为空树
        }

        vector<TreeNode*> allTrees;
        
        for (int rootVal = start; rootVal <= end; ++rootVal) {
            // 生成左子树
            vector<TreeNode*> leftTrees = generate(start, rootVal - 1);
            // 生成右子树
            vector<TreeNode*> rightTrees = generate(rootVal + 1, end);

            // 组合左子树和右子树
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(rootVal); // 创建当前根节点
                    root->left = left;
                    root->right = right;
                    allTrees.push_back(root); // 将生成的树加入到结果中
                }
            }
        }
        return allTrees;
    }
};

