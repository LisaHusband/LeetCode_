# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumNumbers(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        total_sum = 0
        queue = deque([(root, root.val)])  # 初始化队列，包含根节点和根节点的值
        
        while queue:
            node, current_sum = queue.popleft()
            
            # 如果是叶子节点，累加当前的数字
            if not node.left and not node.right:
                total_sum += current_sum
            # 如果有左子节点，加入队列
            if node.left:
                queue.append((node.left, current_sum * 10 + node.left.val))
            # 如果有右子节点，加入队列
            if node.right:
                queue.append((node.right, current_sum * 10 + node.right.val))
        
        return total_sum