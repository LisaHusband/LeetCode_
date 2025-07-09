# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# 变种BFS
class Solution:
    def minDepth(self, root: Optional[TreeNode]) -> int:
        if not root:
            return 0
        
        queue = deque()
        queue.append((root, 1))  # (节点, 当前深度)

        while queue:
            node, depth = queue.popleft()

            # 如果是叶子节点，返回当前深度
            if not node.left and not node.right:
                return depth

            if node.left:
                queue.append((node.left, depth + 1))
            if node.right:
                queue.append((node.right, depth + 1))

        return 0  # 不会到达这里，仅为防御性代码