/**
作者：灵茶山艾府
链接：https://leetcode.cn/problems/merge-intervals/solutions/2798138/jian-dan-zuo-fa-yi-ji-wei-shi-yao-yao-zh-f2b3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
**/
func merge(intervals [][]int) (ans [][]int) {
    slices.SortFunc(intervals, func(p, q []int) int { return p[0] - q[0] }) // 按照左端点从小到大排序
    for _, p := range intervals {
        m := len(ans)
        if m > 0 && p[0] <= ans[m-1][1] { // 可以合并
            ans[m-1][1] = max(ans[m-1][1], p[1]) // 更新右端点最大值
        } else { // 不相交，无法合并
            ans = append(ans, p) // 新的合并区间
        }
    }
    return
}



