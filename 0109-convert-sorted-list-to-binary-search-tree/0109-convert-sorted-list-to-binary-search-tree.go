package main

import "fmt"


// 自定义迭代器类
type ArrayIterator struct {
    nums  []int
    index int
}

func (it *ArrayIterator) next() int {
    if it.index < len(it.nums) {
        value := it.nums[it.index]
        it.index++
        return value
    }
    return -1 // 如果没有更多元素，返回 -1
}

func (it *ArrayIterator) hasNext() bool {
    return it.index < len(it.nums)
}

// Solution: 将有序链表转换为平衡二叉搜索树
func sortedListToBST(head *ListNode) *TreeNode {
    // Step 1: 将链表转换为有序数组
    nums := []int{}
    for head != nil {
        nums = append(nums, head.Val)
        head = head.Next
    }

    // Step 2: 创建自定义迭代器
    numsIter := ArrayIterator{nums: nums}

    // Step 3: 使用自定义迭代器递归构建平衡二叉搜索树
    return buildTree(&numsIter, 0, len(nums)-1)
}

func buildTree(numsIter *ArrayIterator, start, end int) *TreeNode {
    if start > end {
        return nil
    }

    mid := (start + end) / 2
    nodeVal := numsIter.nums[mid]
    node := &TreeNode{Val: nodeVal}

    node.Left = buildTree(numsIter, start, mid-1)  // 递归构建左子树
    node.Right = buildTree(numsIter, mid+1, end)   // 递归构建右子树

    return node
}

// Helper function to print the tree (inorder traversal)
func inorderTraversal(root *TreeNode) {
    if root != nil {
        inorderTraversal(root.Left)
        fmt.Printf("%d ", root.Val)
        inorderTraversal(root.Right)
    }
}


