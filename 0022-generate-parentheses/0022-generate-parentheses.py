class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        result = []
    
        def backtrack(current_string, open_count, close_count):
            # 如果构建的字符串长度为 2 * n，表示我们已经得到一个有效的括号组合
            if len(current_string) == 2 * n:
                result.append(current_string)
                return
            
            # 如果开括号数量小于 n，继续添加开括号
            if open_count < n:
                backtrack(current_string + "(", open_count + 1, close_count)
            
            # 如果闭括号数量小于开括号数量，继续添加闭括号
            if close_count < open_count:
                backtrack(current_string + ")", open_count, close_count + 1)
            
        # 从空字符串开始，初始开括号数量和闭括号数量都为 0
        backtrack("", 0, 0)
        return result
