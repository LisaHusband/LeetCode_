class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        numbers = list(range(1, n+1))
        k -= 1  # 将k调整为0索引，方便计算
        result = []

        def backtrack(nums, k):
            if len(nums) == 1:
                return str(nums[0])
            n = len(nums)
            block_size = factorial(n-1)
            index = k // block_size
            result = str(nums[index])
            nums.pop(index)
            k %= block_size
            return result + backtrack(nums, k)

        return backtrack(numbers, k)