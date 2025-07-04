class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        if target in nums:
            return nums.index(target)
        else:
            for i in range(len(nums)):
                if i==0:
                    if nums[i] > target:
                        return 0
                else:
                    if nums[i-1] < target < nums[i]:
                        return i
        return len(nums)