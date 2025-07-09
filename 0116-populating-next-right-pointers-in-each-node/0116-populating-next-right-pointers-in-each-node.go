/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Left *Node
 *     Right *Node
 *     Next *Node
 * }
 */

func connect(root *Node) *Node {
	if root == nil || root.Left == nil {
        return root
    }

    // 左子节点指向右子节点
    root.Left.Next = root.Right

    // 右子节点指向父节点的 next 的左子节点（如果存在）
    if root.Next != nil {
        root.Right.Next = root.Next.Left
    }

    // 递归连接左右子树
    connect(root.Left)
    connect(root.Right)

    return root
}