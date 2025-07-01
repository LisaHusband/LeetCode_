class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left < right) {
            // 计算当前左右指针形成的容器面积
            int area = min(height[left], height[right]) * (right - left);
            max_area = max(max_area, area);

            // 移动较短的一边，尝试增加面积
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }

        return max_area;
    }
};