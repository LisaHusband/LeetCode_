class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int l = s.size();
        

        // 处理罗马数字的其他情况
        s += "*";  // 添加结束标志避免越界

        for (int i = 0; i < l; ++i) {
            if (s[i] == 'I') {
                result += (i + 1 < l && s[i + 1] == 'V') ? 4 : 
                          (i + 1 < l && s[i + 1] == 'X') ? 9 : 1;
                i += (i + 1 < l && (s[i + 1] == 'V' || s[i + 1] == 'X')) ? 1 : 0;
            } else if (s[i] == 'V') {
                result += (i - 1 >= 0 && s[i - 1] == 'I') ? 0 : 5;
            } else if (s[i] == 'X') {
                result += (i - 1 >= 0 && s[i - 1] == 'I') ? 0 :
                          (i + 1 < l && s[i + 1] == 'L') ? 40 :
                          (i + 1 < l && s[i + 1] == 'C') ? 90 : 10;
                i += (i + 1 < l && (s[i + 1] == 'L' || s[i + 1] == 'C')) ? 1 : 0;
            } else if (s[i] == 'L') {
                result += (i - 1 >= 0 && s[i - 1] == 'X') ? 0 : 50;
            } else if (s[i] == 'C') {
                result += (i + 1 < l && s[i + 1] == 'D') ? 400 :
                          (i - 1 >= 0 && s[i - 1] == 'X') ? 0 :
                          (i + 1 < l && s[i + 1] == 'M') ? 900 : 100;
                i += (i + 1 < l && (s[i + 1] == 'D' || s[i + 1] == 'M')) ? 1 : 0;
            } else if (s[i] == 'D') {
                result += (i - 1 >= 0 && s[i - 1] == 'C') ? 0 : 500;
            } else if (s[i] == 'M') {
                result += (i - 1 >= 0 && s[i - 1] == 'C') ? 0 : 1000;
            }
        }

        return result;
    }
};