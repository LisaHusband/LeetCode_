class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        nums.sort()  # 排序，使得相同的元素相邻
        res = set()  # 用于存储子集，去除重复
        
        # 枚举子集的大小
        for size in range(len(nums) + 1):
            for comb in combinations(nums, size):  # 生成所有大小为size的组合
                res.add(comb)  # 使用集合自动去重
        
        # 返回排序后的子集列表
        return [list(comb) for comb in sorted(res)]