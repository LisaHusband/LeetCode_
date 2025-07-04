#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char num, 
                  vector<int>& rowMask, vector<int>& colMask, vector<int>& boxMask) {
        int numBit = 1 << (num - '1');  // 把数字转换为对应的二进制位
        
        // 检查该数字在当前行、列和子宫是否已经出现
        if (rowMask[row] & numBit || colMask[col] & numBit || boxMask[(row / 3) * 3 + col / 3] & numBit)
            return false;

        return true;
    }

    bool solve(vector<vector<char>>& board, 
                     vector<int>& rowMask, vector<int>& colMask, vector<int>& boxMask) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    // 尝试所有数字1-9
                    for (char num = '1'; num <= '9'; num++) {
                        if (isValid(board, row, col, num, rowMask, colMask, boxMask)) {
                            board[row][col] = num;
                            int numBit = 1 << (num - '1');
                            rowMask[row] |= numBit;  // 更新行的状态
                            colMask[col] |= numBit;  // 更新列的状态
                            boxMask[(row / 3) * 3 + col / 3] |= numBit;  // 更新子宫的状态

                            // 递归填充下一个空格
                            if (solve(board, rowMask, colMask, boxMask))
                                return true;
                            
                            // 回溯
                            board[row][col] = '.';
                            rowMask[row] &= ~numBit;  // 回退行的状态
                            colMask[col] &= ~numBit;  // 回退列的状态
                            boxMask[(row / 3) * 3 + col / 3] &= ~numBit;  // 回退子宫的状态
                        }
                    }
                    return false;  // 如果没有找到合适的数字，回溯
                }
            }
        }
        return true;  // 所有格子已填满
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<int> rowMask(9, 0), colMask(9, 0), boxMask(9, 0);

        // 初始化已有的数字的位图状态
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    int numBit = 1 << (board[row][col] - '1');
                    rowMask[row] |= numBit;
                    colMask[col] |= numBit;
                    boxMask[(row / 3) * 3 + col / 3] |= numBit;
                }
            }
        }

        solve(board, rowMask, colMask, boxMask);
    }
};

