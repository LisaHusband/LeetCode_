class Solution {
public:
    int jump(vector<int>& nums) {
       int n = nums.size();
        if (n <= 1) return 0;  // 如果数组长度为 1 或更小，说明已经在终点，不需要跳跃
        
        int jumps = 0;          // 记录跳跃次数
        int current_end = 0;    // 当前跳跃的最远位置
        int farthest = 0;       // 当前跳跃范围内能够到达的最远位置
        
        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);  // 更新能到达的最远位置
            
            // 如果到达当前跳跃的最远位置，需要进行跳跃
            if (i == current_end) {
                jumps++;  // 跳跃一次
                current_end = farthest;  // 更新跳跃的最远位置
                
                if (current_end >= n - 1) break;  // 如果已经可以到达终点，结束
            }
        }
        
        return jumps; 
    }
};