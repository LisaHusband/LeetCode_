class Solution {
public:
    /**
        Original implementation with explanations by ChatGPT.
        Time Complexity: O(m * n)
        Space Complexity: O(m * n)
        Where m = len(s), n = len(p)
        // 快速剪枝1：如果模式仅是 ".*"，必匹配任意字符串
        if (p == ".*") return true;
    **/
        
    bool isMatch(string s, string p) {
        if (p == ".*") return true;
        const int MAXN = 20; // 假设模式长度最大100
        int m = s.size(), n = p.size();
        bitset<MAXN + 1> dp_current, dp_prev;
        dp_prev.set(0);  // dp[0][0] = true

        // 初始化空字符串与模式匹配
        for (int j = 2; j <= n; j += 2) {
            if (p[j - 1] == '*' && dp_prev[j - 2]) {
                dp_prev.set(j);
            }
        }

        for (int i = 1; i <= m; ++i) {
            dp_current.reset();
            // dp[i][0] = false (空模式不匹配非空字符串)

            bool prev = dp_prev[0]; // dp[i-1][j-1]
            for (int j = 1; j <= n; ++j) {
                bool temp = dp_prev[j]; // dp[i-1][j]
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    if (prev) dp_current.set(j);
                    else dp_current.reset(j);
                }
                else if (p[j - 1] == '*') {
                    bool zeroOccur = dp_current[j - 2]; // dp[i][j-2]
                    bool oneOrMoreOccur = false;
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        oneOrMoreOccur = temp; // dp[i-1][j]
                    }
                    if (zeroOccur || oneOrMoreOccur) dp_current.set(j);
                    else dp_current.reset(j);
                }
                else {
                    dp_current.reset(j);
                }
                prev = temp;
            }
            dp_prev = dp_current; // 下一行
        }

        return dp_prev[n];
    }
};
