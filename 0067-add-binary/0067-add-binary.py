class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 将二进制字符串转换为整数
        int_a = int(a, 2)
        int_b = int(b, 2)
        
        # 计算二者的和
        total = int_a + int_b
        
        # 将结果转换回二进制字符串，并去掉前缀 "0b"
        return bin(total)[2:]