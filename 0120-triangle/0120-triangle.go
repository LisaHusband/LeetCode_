func minimumTotal(triangle [][]int) int {
    if len(triangle) == 0 {
        return 0
    }

    dp := make([]int, len(triangle[0]))
    copy(dp, triangle[0])

    for i := 1; i < len(triangle); i++ {
        newDp := make([]int, i+1)
        for j := 0; j <= i; j++ {
            if j == 0 {
                newDp[j] = dp[j] + triangle[i][j]
            } else if j == i {
                newDp[j] = dp[j-1] + triangle[i][j]
            } else {
                if dp[j-1] < dp[j] {
                    newDp[j] = dp[j-1] + triangle[i][j]
                } else {
                    newDp[j] = dp[j] + triangle[i][j]
                }
            }
        }
        dp = newDp
    }

    minVal := dp[0]
    for _, v := range dp {
        if v < minVal {
            minVal = v
        }
    }
    return minVal
}