class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target in nums:
            f_index = nums.index(target)
            nums.reverse()
            b_index = len(nums) - nums.index(target) -1
            return [f_index, b_index]
        return [-1, -1]