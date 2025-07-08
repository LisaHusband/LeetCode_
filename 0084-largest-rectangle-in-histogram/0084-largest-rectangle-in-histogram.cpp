class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0); // 哨兵柱，用于清空栈
        const int* begin = heights.data();
        const int* end = begin + heights.size();

        stack<const int*> st;  // 存储指针而非索引
        int max_area = 0;

        for (const int* p = begin; p < end; ++p) {
            while (!st.empty() && *st.top() > *p) {
                const int* h_ptr = st.top();
                st.pop();
                const int* l_ptr = st.empty() ? begin - 1 : st.top();
                int width = p - l_ptr - 1;
                max_area = max(max_area, (*h_ptr) * width);
            }
            st.push(p);
        }

        return max_area;
    }
};