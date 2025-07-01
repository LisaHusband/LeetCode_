class Solution {
public:
    /**
        Original implementation with explanations by ChatGPT.
        Time Complexity: O(m * n)
        Space Complexity: O(m * n)
        Where m = len(s), n = len(p)
    **/
    bool isMatch(string s, string p) {
        // 快速剪枝：如果模式仅是 ".*"，必匹配任意字符串
        if (p == ".*") return true;
        int m = s.size(), n = p.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true;  // 空字符串与空模式匹配

        // 处理空字符串与模式匹配的初始化（a*, a*b* 等）
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*' && dp[j - 2]) {
                dp[j] = true;
            }
        }

        for (int i = 1; i <= m; ++i) {
            bool prev = dp[0];  // dp[i-1][j-1] 的前一个状态，初始对应 dp[0][0]
            dp[0] = false;       // 空模式不能匹配非空字符串

            for (int j = 1; j <= n; ++j) {
                bool temp = dp[j];  // 保存 dp[i-1][j]，下一步计算要用
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    dp[j] = prev;
                }
                else if (p[j - 1] == '*') {
                    dp[j] = dp[j - 2];  // '*' 表示0次
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[j] = dp[j] || temp;  // '*' 表示1次或多次
                    }
                }
                else {
                    dp[j] = false;
                }
                prev = temp;  // 更新 prev，为下一 j 循环保存 dp[i-1][j-1]
            }
        }

        return dp[n];
    }
};
