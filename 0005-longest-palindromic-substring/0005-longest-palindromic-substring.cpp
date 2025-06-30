class Solution {
public:
    string preprocess(const string& s) {
        string t = "^";
        for (char c : s) {
            t += "#" + string(1, c);
        }
        t += "#$";
        return t;
    }
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        string t = preprocess(s);
        int n = t.size();
        vector<int> p(n, 0);  // p[i] 记录以 t[i] 为中心的最长回文半径（包含自己）

        int center = 0, right = 0;  // 当前回文最右边界和对应中心
        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;  // i 关于 center 的镜像点

            if (i < right)
                p[i] = min(right - i, p[mirror]);  // 利用镜像减少扩展次数

            // 中心扩展
            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                ++p[i];

            // 更新当前最右边界和中心
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        // 找最大回文长度及其中心位置
        int max_len = 0;
        int center_index = 0;
        for (int i = 1; i < n - 1; ++i) {
            if (p[i] > max_len) {
                max_len = p[i];
                center_index = i;
            }
        }

        // 计算回文子串在原串中的起始位置
        int start = (center_index - max_len) / 2;
        return s.substr(start, max_len);
    }
};