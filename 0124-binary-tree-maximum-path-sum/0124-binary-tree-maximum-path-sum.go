/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxPathSum(root *TreeNode) int {
    // 初始化最大路径和为负无穷
    maxSum := math.MinInt32

    // 深度优先搜索的辅助函数
    var dfs func(node *TreeNode) int
    dfs = func(node *TreeNode) int {
        if node == nil {
            return 0
        }

        // 递归计算左子树和右子树的最大路径和
        leftGain := max(dfs(node.Left), 0)  // 如果为负数，就不考虑
        rightGain := max(dfs(node.Right), 0)

        // 当前节点的路径和（包括左子树和右子树）
        currentPathSum := node.Val + leftGain + rightGain

        // 更新最大路径和
        maxSum = max(maxSum, currentPathSum)

        // 返回经过当前节点的路径和（不包括两边子树）
        return node.Val + max(leftGain, rightGain)
    }

    // 启动 DFS 遍历
    dfs(root)

    return maxSum
}
// 辅助函数，返回较大的两个数
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}