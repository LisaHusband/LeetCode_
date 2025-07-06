class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        length = 0
        i = len(s) - 1
        
        # 跳过末尾空格
        while i >= 0 and s[i] == ' ':
            i -= 1
            
        # 统计最后一个单词长度
        while i >= 0 and s[i] != ' ':
            length += 1
            i -= 1
        
        return length