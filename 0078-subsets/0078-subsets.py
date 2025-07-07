class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        # 生成所有可能的子集，大小从 0 到 len(nums)
        for k in range(len(nums) + 1):
            result.extend(combinations(nums, k))  # 将每个组合添加到结果中
        
        return [list(comb) for comb in result]