class Solution {
public:
void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        // 如果到达数组的末尾，说明找到一个全排列
        if (start == nums.size()) {
            result.push_back(nums);  // 保存当前的排列
            return;
        }

        // 遍历当前的数组元素，并交换以产生新的排列
        for (int i = start; i < nums.size(); ++i) {
            // 交换元素，产生新的排列
            swap(nums[start], nums[i]);
            
            // 递归，处理下一个位置
            backtrack(nums, start + 1, result);
            
            // 还原交换，回溯
            swap(nums[start], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        
        // 递归函数
        backtrack(nums, 0, result);
        
        return result;
    }
};