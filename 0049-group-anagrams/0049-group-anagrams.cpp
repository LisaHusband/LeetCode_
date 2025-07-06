class Solution {
public:
    unsigned long long multiply(unsigned long long base, unsigned long long factor) {
        return base * factor;  // 这里是快速乘法的一个简单实现
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 每个字母对应一个质数，a对应107，b对应3，... 按顺序
        vector<int> prime = {107, 3, 2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59,
                             61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

        unordered_map<unsigned long long, vector<string>> hash;
        
        for (auto& s : strs) {
            unsigned long long key = 1;
            for (char c : s) {
                int idx = c - 96;  // 字符减去 'a'，保证从0开始索引prime数组
                key = multiply(key, prime[idx]);  // 快速乘法
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