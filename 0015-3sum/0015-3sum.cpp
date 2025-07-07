#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());  // 排序
        
        int n = nums.size();
        if (nums[n - 1] < 0) {
            return result;
        }

        int *start = &nums[0], *end = &nums[n - 1]; // 使用指针代替索引

        for (int *i = start; i <= end; ++i) {
            // 剪枝1: 如果当前nums[i]大于0，那么后面的数字必然大于0
            // 直接结束循环，因为没有可能形成和为0的三元组
            if (*i > 0) break;
            // 剪枝2: 跳过重复的元素
            if (i != start && *i == *(i - 1)) continue;

            // 剪枝3: 如果 nums[first] + nums[n-2] + nums[n-1] < 0，不可能有三元组和为0
            if (*i + *(end - 1) + *end < 0) continue;

            int target = -(*i);  // 剩余的两个数的和应该为 -nums[i]
            int *left = i + 1, *right = end;

            while (left < right) {
                int sum = *left + *right;
                if (sum == target) {
                    result.push_back({*i, *left, *right});

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
