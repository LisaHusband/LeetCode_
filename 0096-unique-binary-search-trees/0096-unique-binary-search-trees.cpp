class Solution {
public:
    int numTrees(int n) {
        // dp[i] 表示由 i 个节点组成的二叉搜索树的种数
        vector<long> dp(n + 1, 0);
        
        // 初始化边界条件
        dp[0] = 1;  // 空树的情况
        dp[1] = 1;  // 只有一个节点的情况
        
        // 从 2 到 n 计算 dp[i]
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        
        return dp[n];
    }
};

