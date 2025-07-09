#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;

        int* shortFromLeft = new int[n];   // 左边第一个比当前小的柱子下标
        int* shortFromRight = new int[n];  // 右边第一个比当前小的柱子下标

        shortFromLeft[0] = -1;
        shortFromRight[n - 1] = n;

        // 计算每个柱子左边第一个比它矮的位置
        for (int i = 1; i < n; ++i) {
            int p = i - 1;
            while (p >= 0 && heights[p] >= heights[i]) {
                p = shortFromLeft[p];
            }
            shortFromLeft[i] = p;
        }

        // 计算每个柱子右边第一个比它矮的位置
        for (int i = n - 2; i >= 0; --i) {
            int p = i + 1;
            while (p < n && heights[p] >= heights[i]) {
                p = shortFromRight[p];
            }
            shortFromRight[i] = p;
        }

        // 计算最大面积
        int maxArea = 0;
        for (int i = 0; i < n; ++i) {
            int width = shortFromRight[i] - shortFromLeft[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        // 释放动态分配的内存
        delete[] shortFromLeft;
        delete[] shortFromRight;

        return maxArea;
    }
};
