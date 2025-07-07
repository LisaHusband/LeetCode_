#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int row = grid.size();
        int col = grid[0].size();

        // 创建一个 dp 数组
        vector<vector<int>> dp(row, vector<int>(col, 0));

        // 设置起始点
        dp[0][0] = grid[0][0];

        // 初始化第一列
        for (int i = 1; i < row; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // 初始化第一行
        for (int i = 1; i < col; ++i) {
            dp[0][i] = dp[0][i - 1] + grid[0][i];
        }

        // 填充剩余的 dp 数组
        for (int i = 1; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        return dp[row - 1][col - 1];
    }
};