package main

import "fmt"

func uniquePathsWithObstacles(grid [][]int) int {
    m, n := len(grid), len(grid[0])
    
    // 创建一个 m x n 的 dp 数组
    dp := make([][]int, m)
    for i := range dp {
        dp[i] = make([]int, n)
    }
    
    // 如果起点有障碍物，则直接返回 0
    if grid[0][0] == 1 {
        return 0
    }
    
    // 初始化起点 dp[0][0] = 1
    dp[0][0] = 1
    
    // 填充第一列
    for i := 1; i < m; i++ {
        if grid[i][0] == 0 {
            dp[i][0] = dp[i-1][0]
        }
    }
    
    // 填充第一行
    for j := 1; j < n; j++ {
        if grid[0][j] == 0 {
            dp[0][j] = dp[0][j-1]
        }
    }
    
    // 填充剩下的 dp 数组
    for i := 1; i < m; i++ {
        for j := 1; j < n; j++ {
            if grid[i][j] == 0 { // 如果没有障碍物
                dp[i][j] = dp[i-1][j] + dp[i][j-1]
            }
        }
    }
    
    // 返回右下角的路径数
    return dp[m-1][n-1]
}
