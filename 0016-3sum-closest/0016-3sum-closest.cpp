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
        for (int i = 0; i < l; i++) {
            
            int left = i + 1;
            int right = l - 1;
            

            while (left < right) {
                int sums = nums[left] + nums[right] + nums[i];

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
                // 剪枝：如果当前值已经大于目标值的上限，退出循环
            if (nums[i] + nums[nums.size() - 2] + nums[nums.size() - 1] < target) {
                continue;
            }
            }
        }

        return result;
    }
};