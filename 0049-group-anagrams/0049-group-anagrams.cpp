class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 每个字母对应一个质数，a对应2，b对应3，... 按顺序
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59,
                             61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

        unordered_map<unsigned long long, vector<string>> hash;
        
        for (auto& s : strs) {
            unsigned long long key = 1;
            for (char c : s) {
                // 字符减去 'a'，保证从0开始索引prime数组
                int idx = c - 96;
                key *= prime[idx];
            }
            hash[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& p : hash) {
            result.push_back(move(p.second));
        }
        return result;
    }
};