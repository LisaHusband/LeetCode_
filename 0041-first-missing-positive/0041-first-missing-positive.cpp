class Solution {
public:
    // 递归函数：从当前索引开始查找目标正整数
    int recurse(std::vector<int>& nums, int idx, int target) {
        if (idx == nums.size()) {  // 递归结束条件
            return target;
        }

        if (nums[idx] == target) {  // 如果当前数字等于目标数字，递归检查下一个
            return recurse(nums, idx + 1, target + 1);
        } else if (nums[idx] > target) {  // 如果当前数字大于目标，递归继续
            return target;
        }
        
        return recurse(nums, idx + 1, target);  // 否则继续递归
    }
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        // 用于标记元素是否在索引位置上出现过
        std::vector<bool> seen(n + 1, false);  // seen[i] 表示数字 i 是否存在
        
        // 标记数组中的数字
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0 && nums[i] <= n) {
                seen[nums[i]] = true;  // 标记 nums[i] 存在
            }
        }
        
        // 查找第一个未出现的数字
        for (int i = 1; i <= n; ++i) {
            if (!seen[i]) {
                return i;
            }
        }
        
        // 如果所有数字都存在，那么最小的缺失正整数是 n + 1
        return n + 1;
    }
};