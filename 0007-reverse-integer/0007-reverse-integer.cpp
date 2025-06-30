class Solution {
public:
    int reverse(int x) {
        long result = 0;  // 用 long 暂存，避免溢出

        while (x != 0) {
            int digit = x % 10;
            result = result * 10 + digit;
            x /= 10;
        }

        // 检查是否超出 32 位整数范围
        if (result < INT_MIN || result > INT_MAX)
            return 0;

        return static_cast<int>(result);
    }
};