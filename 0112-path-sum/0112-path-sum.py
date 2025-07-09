# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 变种BFS
class Solution:
    def hasPathSum(self, root: Optional[TreeNode], targetSum: int) -> bool:
        if not root:
            return False

        queue = deque()
        queue.append((root, root.val))  # (当前节点, 当前路径和)

        while queue:
            node, current_sum = queue.popleft()

            # 检查是否是叶子节点
            if not node.left and not node.right:
                if current_sum == targetSum:
                    return True

            # 左右子树入队，同时更新路径和
            if node.left:
                queue.append((node.left, current_sum + node.left.val))
            if node.right:
                queue.append((node.right, current_sum + node.right.val))

        return False