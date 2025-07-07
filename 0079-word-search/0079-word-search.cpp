class Solution {
    static constexpr int DIRS[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    bool exist(vector<vector<char>>& board, string word) {
        unordered_map<char, int> cnt;
        for (auto& row : board) {
            for (char c : row) {
                cnt[c]++;
            }
        }

        // 优化一
        unordered_map<char, int> word_cnt;
        for (char c : word) {
            if (++word_cnt[c] > cnt[c]) {
                return false;
            }
        }

        // 优化二
        if (cnt[word.back()] < cnt[word[0]]) {
            ranges::reverse(word);
        }

        int m = board.size(), n = board[0].size();
        auto dfs = [&](this auto&& dfs, int i, int j, int k) -> bool {
            if (board[i][j] != word[k]) { // 匹配失败
                return false;
            }
            if (k + 1 == word.length()) { // 匹配成功！
                return true;
            }
            board[i][j] = 0; // 标记访问过
            for (auto& [dx, dy] : DIRS) {
                int x = i + dx, y = j + dy; // 相邻格子
                if (0 <= x && x < m && 0 <= y && y < n && dfs(x, y, k + 1)) {
                    return true; // 搜到了！
                }
            }
            board[i][j] = word[k]; // 恢复现场
            return false; // 没搜到
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(i, j, 0)) {
                    return true; // 搜到了！
                }
            }
        }
        return false; // 没搜到
    }
};

// 作者：灵茶山艾府
// 链接：https://leetcode.cn/problems/word-search/solutions/2927294/liang-ge-you-hua-rang-dai-ma-ji-bai-jie-g3mmm/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。