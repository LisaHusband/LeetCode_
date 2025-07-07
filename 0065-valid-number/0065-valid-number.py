class Solution:
    def isNumber(self, s: str) -> bool:
        # 使用正则表达式来匹配有效的数字格式
        pattern = r'^[+-]?(\d+(\.\d*)?|\.\d+)([eE][+-]?\d+)?$'
        return bool(re.match(pattern, s.strip()))  # 去掉两边的空格后匹配