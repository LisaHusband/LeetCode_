# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

# 自定义迭代器类
class ArrayIterator:
    def __init__(self, nums):
        self.nums = nums
        self.index = 0
    
    def next(self):
        if self.index < len(self.nums):
            value = self.nums[self.index]
            self.index += 1
            return value
        return None  # 如果没有更多元素，返回 None
    
    def hasNext(self):
        return self.index < len(self.nums)
class Solution:
    def sortedArrayToBST(self, nums: List[int]) -> Optional[TreeNode]:
        # 自定义迭代器来遍历数组
        def buildTree(nums_iter, start, end):
            if start > end:
                return None
            
            mid = (start + end) // 2
            node_val = nums_iter.nums[mid]  # 使用中间值作为当前节点的值
            node = TreeNode(node_val)
            
            node.left = buildTree(nums_iter, start, mid - 1)  # 递归构建左子树
            node.right = buildTree(nums_iter, mid + 1, end)   # 递归构建右子树
            return node
        
        # 创建自定义迭代器
        nums_iter = ArrayIterator(nums)
        
        return buildTree(nums_iter, 0, len(nums) - 1)