/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 // Solution: 判断树是否平衡
type Solution struct{}

// 辅助函数：检查树是否平衡并返回其高度
func checkBalance(root *TreeNode) (bool, int) {
    if root == nil {
        return true, 0 // 空树是平衡的，高度为0
    }

    // 递归检查左右子树的平衡性
    leftBalanced, leftHeight := checkBalance(root.Left)
    rightBalanced, rightHeight := checkBalance(root.Right)

    // 如果左子树或右子树不平衡，则当前树也不平衡
    if !leftBalanced || !rightBalanced {
        return false, 0
    }

    // 如果左右子树高度差大于1，则不平衡
    if abs(leftHeight-rightHeight) > 1 {
        return false, 0
    }

    // 当前节点平衡，返回树的高度
    return true, 1 + max(leftHeight, rightHeight)
}

// isBalanced 判断二叉树是否平衡
func (s *Solution) isBalanced0(root *TreeNode) bool {
    balanced, _ := checkBalance(root)
    return balanced
}

// 求两个数的最大值
func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

// 求绝对值
func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
func isBalanced(root *TreeNode) bool {
    // 创建 Solution 实例并检查树是否平衡
    solution := Solution{}
    return solution.isBalanced0(root)
}