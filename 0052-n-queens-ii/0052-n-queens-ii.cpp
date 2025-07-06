class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> cols(n, false);           // 记录列是否被占用
        vector<bool> diag1(2 * n - 1, false);  // 记录主对角线（row + col）
        vector<bool> diag2(2 * n - 1, false);  // 记录副对角线（row - col + n - 1）

        dfs(0, n, cols, diag1, diag2, count);
        return count;
    }

private:
    void dfs(int row, int n, vector<bool>& cols,
             vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (row == n) {
            count++;
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;  // 剪枝

            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            dfs(row + 1, n, cols, diag1, diag2, count);

            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;  // 回溯
        }
    }
};
