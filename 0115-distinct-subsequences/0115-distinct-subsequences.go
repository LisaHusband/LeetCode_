func numDistinct(s string, t string) int {
    m, n := len(s), len(t)
    if n > m {
        return 0
    }

    dp := make([]uint64, n+1)
    dp[0] = 1 // 空串是任何串的子序列

    for i := 1; i <= m; i++ {
        // 必须从后向前遍历 t，避免覆盖 dp[j-1]
        for j := n; j >= 1; j-- {
            if s[i-1] == t[j-1] {
                dp[j] += dp[j-1]
            }
        }
    }

    return int(dp[n]) // 题目保证不会溢出 int32
}
