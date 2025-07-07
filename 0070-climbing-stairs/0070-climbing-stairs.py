class Solution:
    def climbStairs(self, n: int) -> int:
        if n == 1:
            return 1
        # 初始化前两项
        prev2, prev1 = 1, 2
        
        for i in range(3, n + 1):
            # 当前的方法数是前两项之和
            current = prev1 + prev2
            # 更新 prev2 和 prev1
            prev2 = prev1
            prev1 = current
        
        return prev1

