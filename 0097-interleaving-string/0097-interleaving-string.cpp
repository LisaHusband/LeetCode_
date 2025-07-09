#include <iostream>
#include <cstring>  // for memset

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size();
        int n = s2.size();

        // 如果 s3 的长度不等于 s1 和 s2 的长度之和，直接返回 false
        if (m + n != s3.size()) {
            return false;
        }

        // 使用动态规划来存储结果，初始化为 false
        bool *dp = new bool[(m + 1) * (n + 1)];  // 使用指针操作
        memset(dp, false, sizeof(bool) * (m + 1) * (n + 1));  // 初始化 dp 数组为 false

        // 初始化 dp[0][0] 为 true，表示空字符串可以交错组成空字符串
        dp[0] = true;

        // 填充 dp 数组
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                // 如果 i > 0 且 s1[i-1] == s3[i+j-1]
                if (i > 0 && dp[(i - 1) * (n + 1) + j] && s1[i - 1] == s3[i + j - 1]) {
                    dp[i * (n + 1) + j] = true;
                }
                // 如果 j > 0 且 s2[j-1] == s3[i+j-1]
                if (j > 0 && dp[i * (n + 1) + (j - 1)] && s2[j - 1] == s3[i + j - 1]) {
                    dp[i * (n + 1) + j] = true;
                }
            }
        }

        bool result = dp[m * (n + 1) + n];  // 最终结果存储在 dp[m][n] 中

        delete[] dp;  // 释放动态分配的内存
        return result;
    }
};
