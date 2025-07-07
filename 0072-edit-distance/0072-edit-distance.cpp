#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        // 创建一个 (m+1) x (n+1) 的 dp 表，初始化为 -1 表示尚未计算
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        
        // 定义递归加记忆化的函数
        return dfs(word1, word2, m - 1, n - 1, dp);
    }
    
private:
    int dfs(const string& word1, const string& word2, int i, int j, vector<vector<int>>& dp) {
        // 边界条件
        if (i < 0) return j + 1;  // word1已经空了，剩下的全是插入操作
        if (j < 0) return i + 1;  // word2已经空了，剩下的全是删除操作
        
        // 如果已经计算过，直接返回结果
        if (dp[i][j] != -1) return dp[i][j];
        
        // 如果字符相同，不需要操作，递归到下一字符
        if (word1[i] == word2[j]) {
            return dp[i][j] = dfs(word1, word2, i - 1, j - 1, dp);
        } else {
            // 计算三种操作的最小值
            return dp[i][j] = min({dfs(word1, word2, i - 1, j, dp) + 1,  // 删除
                                   dfs(word1, word2, i, j - 1, dp) + 1,  // 插入
                                   dfs(word1, word2, i - 1, j - 1, dp) + 1});  // 替换
        }
    }
};

