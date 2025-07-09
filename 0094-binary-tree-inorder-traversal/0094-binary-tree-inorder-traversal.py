# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        result = []
        stack = []
        current = root
        
        # 迭代模拟递归过程
        while current or stack:
            # 一直遍历左子树
            while current:
                stack.append(current)
                current = current.left
            
            # 弹出栈顶元素并访问它
            current = stack.pop()
            result.append(current.val)
            
            # 转向右子树
            current = current.right
        
        return result