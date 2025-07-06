class Solution:
    def spiralOrder(self, matrix):
        if not matrix:
            return []
        
        res = []
        top, bottom = 0, len(matrix) - 1
        left, right = 0, len(matrix[0]) - 1
        
        while left <= right and top <= bottom:
            # 从左到右
            for j in range(left, right + 1):
                res.append(matrix[top][j])
            top += 1
            
            # 从上到下
            for i in range(top, bottom + 1):
                res.append(matrix[i][right])
            right -= 1
            
            if top <= bottom:
                # 从右到左
                for j in range(right, left - 1, -1):
                    res.append(matrix[bottom][j])
                bottom -= 1
            
            if left <= right:
                # 从下到上
                for i in range(bottom, top - 1, -1):
                    res.append(matrix[i][left])
                left += 1
        
        return res
