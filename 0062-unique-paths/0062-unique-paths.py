class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        from math import comb  # Python 3.8+ 支持 comb 函数
        return comb(m + n - 2, m - 1)
