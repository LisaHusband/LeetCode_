class Solution:
    def myPow(self, x: float, n: int) -> float:
        def quick_pow(x, n):
            result = 1.0
            while n > 0:
                if n & 1:  # 如果当前位是1
                    result *= x
                x *= x
                n >>= 1
            return result

        if n == 0:
            return 1.0
        elif n < 0:
            return 1.0 / quick_pow(x, -n)
        else:
            return quick_pow(x, n)