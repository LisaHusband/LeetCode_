# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pathSum(self, root: Optional[TreeNode], targetSum: int) -> List[List[int]]:
        if not root:
            return []

        result = []
        queue = deque()
        # 每个元素为 (当前节点, 当前路径和, 当前路径列表)
        queue.append((root, root.val, [root.val]))

        while queue:
            node, curr_sum, path = queue.popleft()

            # 如果是叶子节点并且和等于目标值，加入结果
            if not node.left and not node.right and curr_sum == targetSum:
                result.append(path)

            # 左子节点入队
            if node.left:
                queue.append((node.left, curr_sum + node.left.val, path + [node.left.val]))

            # 右子节点入队
            if node.right:
                queue.append((node.right, curr_sum + node.right.val, path + [node.right.val]))

        return result