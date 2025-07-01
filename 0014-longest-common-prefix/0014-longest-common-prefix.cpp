class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string pre = "";
        
        // 检查字符串数组的长度
        if (strs.size() >= 1 && strs.size() <= 200) {
            int l = strs[0].size();
            
            // 遍历第一个字符串的每个字符
            for (int i = 0; i < l; ++i) {
                bool match = true;
                
                // 检查其他字符串是否有相同的字符
                for (int j = 1; j < strs.size(); ++j) {
                    if (strs[j][i] != strs[0][i]) {
                        match = false;
                        break;
                    }
                }
                
                // 如果所有字符串的该位置字符都匹配
                if (match) {
                    pre += strs[0][i];
                } else {
                    break;
                }
            }
        } else if (strs.size() == 1) {
            pre = strs[0];  // 如果只有一个字符串，则直接返回该字符串
        } else {
            pre = "";  // 如果没有字符串，返回空字符串
        }
        
        return pre;
    }
};