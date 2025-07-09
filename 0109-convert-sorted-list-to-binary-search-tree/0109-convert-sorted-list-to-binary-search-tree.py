# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
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
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        # Step 1: 将链表转换为有序数组
        nums = []
        while head:
            nums.append(head.val)
            head = head.next
        
        # Step 2: 创建自定义迭代器
        nums_iter = ArrayIterator(nums)
        
        # Step 3: 使用自定义迭代器递归构建平衡二叉搜索树
        def buildTree(nums_iter, start, end):
            if start > end:
                return None
            
            mid = (start + end) // 2
            node_val = nums_iter.nums[mid]  # 获取中间值
            node = TreeNode(node_val)
            
            node.left = buildTree(nums_iter, start, mid - 1)  # 递归构建左子树
            node.right = buildTree(nums_iter, mid + 1, end)   # 递归构建右子树
            return node
        
        # Step 4: 返回构建好的树的根节点
        return buildTree(nums_iter, 0, len(nums) - 1)

# 作者：LisaHusband
# 链接：https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/solutions/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。