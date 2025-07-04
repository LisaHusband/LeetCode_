class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 使用整数来表示每行、每列和每个3x3宫的数字的位图
        vector<int> rows(9, 0);    // 每行的位图
        vector<int> cols(9, 0);    // 每列的位图
        vector<int> boxes(9, 0);   // 每个3x3宫的位图

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char num = board[i][j];
                if (num == '.') continue;  // 跳过空格

                int bit = 1 << (num - '1');  // 计算数字的位图，'1' -> 0, '2' -> 1, ..., '9' -> 8

                int boxIndex = (i / 3) * 3 + j / 3;  // 计算所在的3x3宫的索引

                // 检查该数字在行、列或宫内是否已出现
                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[boxIndex] & bit)) {
                    return false;  // 如果有重复，则返回false
                }

                // 设置当前数字的位图
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[boxIndex] |= bit;
            }
        }

        return true;  // 所有检查通过，数独有效
    }
};