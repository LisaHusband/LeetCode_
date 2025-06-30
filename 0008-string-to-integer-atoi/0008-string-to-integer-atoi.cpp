class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        // 跳过前导空格
        while (i < n && s[i] == ' ') i++;

        // 处理符号
        int sign = 1;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long result = 0;
        // 边读取边转换
        while (i < n && isdigit(s[i])) {
            result = result * 10 + (s[i] - '0');

            // 溢出检测
            if (sign == 1 && result > INT_MAX) return INT_MAX;
            if (sign == -1 && -result < INT_MIN) return INT_MIN;

            i++;
        }

        return static_cast<int>(sign * result);
    }
};