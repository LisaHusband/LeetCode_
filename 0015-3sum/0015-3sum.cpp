#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());  // 排序
        
        int n = nums.size();
        if (nums[n-1] < 0) {
            return result;  // 如果最大数小于0，三元组和无法为0
        }

        for (int i = 0; i < n; ++i) {
            // 剪枝1: 如果当前 nums[i] > 0，直接结束循环
            if (nums[i] > 0) break;
            // 剪枝2: 跳过重复的元素
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            // 剪枝3: 如果 nums[i] + nums[n-2] + nums[n-1] < 0，不可能有三元组和为0
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0) continue;
            
            int target = -nums[i];  // 剩余两个数的和应该为 -nums[i]
            int *left = &nums[i + 1], *right = &nums[n - 1];  // 指针操作
            
            while (left < right) {
                int sum = *left + *right;
                
                if (sum == target) {
                    result.push_back({nums[i], *left, *right});
                    
                    // 跳过重复的元素
                    while (left < right && *left == *(left + 1)) left++;
                    while (left < right && *right == *(right - 1)) right--;
                    
                    // 移动指针
                    left++, right--;
                } 
                else if (sum < target) {
                    left++;
                } 
                else {
                    right--;
                }
            }
        }
        
        return result;
    }
};
