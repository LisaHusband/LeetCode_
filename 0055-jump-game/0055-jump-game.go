func canJump(nums []int) bool {
    maxReach := 0
    for i, jump := range nums {
        if i > maxReach {
            return false
        }
        if i+jump > maxReach {
            maxReach = i + jump
        }
    }
    return true
}
