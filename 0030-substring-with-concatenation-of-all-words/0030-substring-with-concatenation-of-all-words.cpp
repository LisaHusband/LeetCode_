#include <ranges>
namespace sr = std::ranges;
namespace sv = std::views;
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        const int n = s.size(), m = words.size(), w = words[0].size();
        if (m>1000){
            // 将 words 中的元素放入 set，检查是否只包含一个单词
            unordered_set<string> wordss(words.begin(), words.end());

            // 如果 wordss 中只有一个元素，检查 s 是否只包含一个字符
            if (wordss.size() == 1){
                unordered_set<char> char_set(s.begin(), s.end());  // 将字符串转为 set 用于判断是否只有一个不同字符
                if (char_set.size() == 1) {
                    // 如果 s 中的字符只有一个，并且 wordss 中的唯一元素在 s 中
                    if (s.find(*wordss.begin()) != string::npos) {
                        vector<int> result;
                        // 返回满足条件的索引
                        for (int i = 0; i <= n - w*m; ++i) {
                            result.push_back(i);
                        }
                        return result;
                    }
                    else {
                        return {};  // 如果没有找到，返回空列表
                    }
                }
            }
        }
        
        vector<int> ans;
        unordered_map<string, int> dict, cmp;
        for (const string& str : words)
            dict[str]++;
        if (dict.size() == 1) { // BM算法在哈希表大小为1时退化，此时特殊处理
            string target = sv::join(words) | sr::to<string>();
            for (int pos = 0; (pos = s.find(target, pos)) != string::npos; pos++)
                ans.push_back(pos);
            return ans;
        }
        for (int start : sv::iota(0, w))
            for (int i = start, j; i <= n - w * m; i += w) {
                for (j = i + w * (m - 1); j >= i; j -= w) {
           //注意j-=w这个倒叙匹配，这里决定了亚线性复杂度
                    string str = s.substr(j, w);
                    if (!dict.count(str) || dict[str] == cmp[str]) break;
                    else cmp[str]++;
                    if (j == i) {
                        ans.push_back(j);
                        break;
                    }
                }
                i = j;
                cmp.clear();
            }
        return ans;
    }
};