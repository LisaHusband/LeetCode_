class Solution:
    def simplifyPath(self, path: str) -> str:
        # 用栈来模拟路径的变化
        stack = []
        
        # 按'/'分割路径
        dirs = path.split('/')
        
        for dir in dirs:
            if dir == '' or dir == '.':
                # 空字符串或当前目录，跳过
                continue
            elif dir == '..':
                # 上一级目录，弹出栈顶元素（如果栈不为空）
                if stack:
                    stack.pop()
            else:
                # 有效的目录名，压入栈中
                stack.append(dir)
        
        # 构建简化路径
        return '/' + '/'.join(stack)