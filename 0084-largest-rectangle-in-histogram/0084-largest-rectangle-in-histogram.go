package main

import (
	"fmt"
)

func largestRectangleArea(heights []int) int {
	n := len(heights)
	if n == 0 {
		return 0
	}

	shortFromLeft := make([]int, n)  // 左边第一个比当前小的柱子下标
	shortFromRight := make([]int, n) // 右边第一个比当前小的柱子下标

	shortFromLeft[0] = -1
	shortFromRight[n-1] = n

	// 计算每个柱子左边第一个比它矮的位置
	for i := 1; i < n; i++ {
		p := i - 1
		for p >= 0 && heights[p] >= heights[i] {
			p = shortFromLeft[p]
		}
		shortFromLeft[i] = p
	}

	// 计算每个柱子右边第一个比它矮的位置
	for i := n - 2; i >= 0; i-- {
		p := i + 1
		for p < n && heights[p] >= heights[i] {
			p = shortFromRight[p]
		}
		shortFromRight[i] = p
	}

	// 计算最大面积
	maxArea := 0
	for i := 0; i < n; i++ {
		width := shortFromRight[i] - shortFromLeft[i] - 1
		area := heights[i] * width
		if area > maxArea {
			maxArea = area
		}
	}

	return maxArea
}

