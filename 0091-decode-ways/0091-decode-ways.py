class Solution:
    def numDecodings(self, s: str) -> int:
        if not s:
            return 0
        
        n = len(s)
        dp = [0] * (n + 1)
        dp[0] = 1  # 空字符串的解码方式为1

        for i in range(1, n + 1):
            # 1. 如果当前字符是合法的数字（'1'到'9'）
            if s[i - 1] != '0':
                dp[i] += dp[i - 1]
            
            # 2. 如果前一个字符和当前字符构成的两位数字在10到26之间
            if i > 1 and s[i - 2] != '0' and 10 <= int(s[i - 2:i]) <= 26:
                dp[i] += dp[i - 2]
        
        return dp[n]