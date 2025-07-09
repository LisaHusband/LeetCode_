# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        if n == 0:
            return []

        # 递归生成树的方法
        def generate(start, end):
            if start > end:
                return [None]  # 如果范围为空，返回一个空节点（表示没有树）
            
            all_trees = []
            for root_val in range(start, end + 1):
                # 生成所有左子树
                left_trees = generate(start, root_val - 1)
                # 生成所有右子树
                right_trees = generate(root_val + 1, end)
                
                # 组合左子树和右子树
                for left in left_trees:
                    for right in right_trees:
                        root = TreeNode(root_val)  # 创建当前根节点
                        root.left = left
                        root.right = right
                        all_trees.append(root)  # 将生成的树加入到结果中
            return all_trees
        
        return generate(1, n)