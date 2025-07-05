class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();  // 获取矩阵的大小
        
        // 逐层旋转
        for (int i = 0; i < n / 2; i++) {
            int start = i;
            int end = n - i - 1;
            
            for (int j = start; j < end; j++) {
                int offset = j - start;
                
                // 保存上面的值
                int top = matrix[start][j];
                
                // 左 -> 上
                matrix[start][j] = matrix[end - offset][start];
                
                // 下 -> 左
                matrix[end - offset][start] = matrix[end][end - offset];
                
                // 右 -> 下
                matrix[end][end - offset] = matrix[j][end];
                
                // 上 -> 右
                matrix[j][end] = top;
            }
        }
    }
};