class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // 排序
        
        int result = 0;
        
        // 如果数组有 3 个元素，直接返回它们的和
        if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        int l = nums.size();
        int mit = 10000;  // 初始化最小差值

        // 遍历每一个元素
        for (int i = 0; i < l-2; i++) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) {
                continue; // 优化三
            }
            // 优化一
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) { // 后面无论怎么选，选出的三个数的和不会比 s 还小
                if (s - target < mit) {
                    result = s; // 由于下面直接 break，这里无需更新 min_diff
                }
                break;
            }

            // 优化二
            s = x + nums[l - 2] + nums[l - 1];
            if (s < target) { // x 加上后面任意两个数都不超过 s，所以下面的双指针就不需要跑了
                if (target - s < mit) {
                    mit = target - s;
                    result = s;
                }
                continue;
            }
            int left = i + 1;
            int right = l - 1;
            while (left < right) {
                int sums = nums[left] + nums[right] + x;

                // 更新最接近的和
                if (abs(target - sums) < mit) {
                    result = sums;
                    mit = abs(target - sums);
                }

                // 根据当前和与目标的关系调整指针
                if (sums < target) {
                    left++;
                } else {
                    right--;
                }
        
            }
        }

        return result;
    }
};