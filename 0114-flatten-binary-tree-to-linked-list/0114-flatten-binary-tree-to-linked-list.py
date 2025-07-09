# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def flatten(self, root: Optional[TreeNode]) -> None:
        """
        Do not return anything, modify root in-place instead.
        """
        if not root:
            return

        # Step 1: 先序遍历并保存节点
        stack = [root]
        node_list = []

        while stack:
            node = stack.pop()
            node_list.append(node)
            # 注意：先右后左，确保先序顺序
            if node.right:
                stack.append(node.right)
            if node.left:
                stack.append(node.left)

        # Step 2: 重建链表结构
        for i in range(1, len(node_list)):
            prev = node_list[i - 1]
            curr = node_list[i]
            prev.left = None
            prev.right = curr