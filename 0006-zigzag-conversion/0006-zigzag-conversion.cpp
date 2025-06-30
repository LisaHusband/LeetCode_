class Solution {
public:
    string convert(string s, int numRows) {
         if (numRows <= 1 || s.size() <= numRows) return s;

        string result;
        result.reserve(s.size());

        int cycleLen = 2 * numRows - 2;
        const char* p = s.c_str();
        const char* end = p + s.size();

        // 第 r 行处理
        for (int r = 0; r < numRows; ++r) {
            const char* cur = p + r;
            while (cur < end) {
                result.push_back(*cur);

                // 对于中间行，还需要加一个“对角线”字符
                if (r > 0 && r < numRows - 1) {
                    int diagOffset = cycleLen - 2 * r;
                    const char* diag = cur + diagOffset;
                    if (diag < end) {
                        result.push_back(*diag);
                    }
                }

                // 跳到下一个周期中的当前行
                cur += cycleLen;
            }
        }

        return result;
    }
};