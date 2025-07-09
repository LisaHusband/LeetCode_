class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        # 结果列表，用于存储合法的IP地址
        result = []
        
        # 递归生成所有可能的IP地址
        def backtrack(start, parts):
            if len(parts) == 4:
                # 如果已经有四个部分，检查是否遍历完整个字符串
                if start == len(s):
                    result.append(".".join(parts))
                return
            
            # 尝试切割1到3位
            for length in range(1, 4):
                if start + length > len(s):
                    break  # 越界，提前返回
                
                part = s[start:start + length]
                
                # 判断这个部分是否合法
                if (len(part) > 1 and part[0] == '0') or (int(part) > 255):
                    continue
                
                # 递归处理剩余部分
                backtrack(start + length, parts + [part])

        # 调用回溯
        backtrack(0, [])
        return result