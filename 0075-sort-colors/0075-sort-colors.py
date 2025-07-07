class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        # 计数三个颜色的个数
        count = [0, 0, 0]
        
        # 统计 0、1、2 的出现次数
        for num in nums:
            count[num] += 1
        
        # 用计数结果重新填充原数组
        index = 0
        for color in range(3):
            for _ in range(count[color]):
                nums[index] = color
                index += 1