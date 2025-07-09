package main

import (
	"fmt"
)

func largestRectangleArea(heights []int) int {
	// 添加一个 0 结尾，用于清空栈中所有柱子
	heights = append(heights, 0)
	stack := []int{-1} // 栈中保存索引
	maxArea := 0

	for i := 0; i < len(heights); i++ {
		for len(stack) > 1 && heights[i] < heights[stack[len(stack)-1]] {
			h := heights[stack[len(stack)-1]]
			stack = stack[:len(stack)-1]
			w := i - stack[len(stack)-1] - 1
			area := h * w
			if area > maxArea {
				maxArea = area
			}
		}
		stack = append(stack, i)
	}

	return maxArea
}
