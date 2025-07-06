class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);           // 标记列是否被占用
        vector<bool> diag1(2 * n - 1, false);  // 主对角线（row + col）
        vector<bool> diag2(2 * n - 1, false);  // 副对角线（row - col + n - 1）

        dfs(0, n, board, res, cols, diag1, diag2);
        return res;
    }

    void dfs(int row, int n, vector<string>& board, vector<vector<string>>& res,
             vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            res.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (cols[col] || diag1[row + col] || diag2[row - col + n - 1])
                continue;  // 剪枝：跳过非法放置

            // 放置皇后
            board[row][col] = 'Q';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = true;

            // 递归下一行
            dfs(row + 1, n, board, res, cols, diag1, diag2);

            // 回溯
            board[row][col] = '.';
            cols[col] = diag1[row + col] = diag2[row - col + n - 1] = false;
        }
    }
};
