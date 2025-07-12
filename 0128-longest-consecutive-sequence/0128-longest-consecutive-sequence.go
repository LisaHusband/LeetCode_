func longestConsecutive(nums []int) int {
    if len(nums) == 0 {
		return 0
	}

	// 排序数组
	sort.Ints(nums)

	longest := 1     // 最长连续序列的长度
	currentStreak := 1 // 当前连续序列的长度

	// 遍历排序后的数组
	for i := 1; i < len(nums); i++ {
		if nums[i] == nums[i-1] { // 跳过重复元素
			continue
		} else if nums[i] == nums[i-1]+1 { // 连续
			currentStreak++
		} else { // 不连续，更新最长连续序列的长度
			if currentStreak > longest {
				longest = currentStreak
			}
			currentStreak = 1 // 重置当前连续序列长度
		}
	}

	// 返回最大长度
	if currentStreak > longest {
		longest = currentStreak
	}
	return longest
}