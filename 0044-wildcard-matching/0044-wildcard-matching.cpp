class Solution {
public:
    bool isMatch(string s, string p) {
        int i = 0, j = 0;  // i指向s，j指向p
        int star_idx = -1, match_idx = -1;  // star_idx 记录*的位置，match_idx 记录s匹配的位置
        
        while (i < s.size()) {
            // 匹配字母或 ? 的情况
            if (j < p.size() && (p[j] == s[i] || p[j] == '?')) {
                i++;
                j++;
            }
            // 遇到 * 的情况
            else if (j < p.size() && p[j] == '*') {
                star_idx = j;
                match_idx = i;
                j++;  // *匹配任意长度字符，跳过 *
            }
            // 遇到不匹配的字符，并且之前有 *
            else if (star_idx != -1) {
                j = star_idx + 1;  // 将模式指针回到*后面
                match_idx++;       // 继续尝试匹配 s 中的字符
                i = match_idx;     // 重新设置 s 的指针
            }
            else {
                // 如果没有匹配且没有*，返回false
                return false;
            }
        }
        
        // 处理模式p中的剩余*，跳过它们
        while (j < p.size() && p[j] == '*') {
            j++;
        }

        // 如果模式p遍历完了，返回true
        return j == p.size();
    }
};