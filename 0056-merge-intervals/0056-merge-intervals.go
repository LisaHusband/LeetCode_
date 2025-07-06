func merge(intervals [][]int) [][]int {
    if len(intervals) == 0 {
        return [][]int{}
    }

    // 按起点排序
    sort.Slice(intervals, func(i, j int) bool {
        return intervals[i][0] < intervals[j][0]
    })

    merged := [][]int{}
    currentStart, currentEnd := intervals[0][0], intervals[0][1]

    for _, interval := range intervals[1:] {
        start, end := interval[0], interval[1]
        if start <= currentEnd {
            // 有重叠，更新终点
            if end > currentEnd {
                currentEnd = end
            }
        } else {
            // 无重叠，保存当前区间，更新起点终点
            merged = append(merged, []int{currentStart, currentEnd})
            currentStart, currentEnd = start, end
        }
    }

    // 添加最后一个区间
    merged = append(merged, []int{currentStart, currentEnd})

    return merged
}
