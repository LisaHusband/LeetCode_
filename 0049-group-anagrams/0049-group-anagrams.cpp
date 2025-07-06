class Solution {
public:
    // 快速乘法，通过指数来优化乘法运算
    unsigned long long multiplyFast(unsigned long long base, int prime) {
        unsigned long long result = base;
        for (int i = 1; i < prime; i++) {
            result *= prime;  // 通过指数优化乘法
        }
        return result;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 每个字母对应一个质数，a对应2，b对应3，... 按顺序
        vector<int> prime = {107, 3, 2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59,
                             61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };

        unordered_map<unsigned long long, vector<string>> hash;
        
        // 快速乘法函数
        auto mul = [](unsigned long long a, unsigned long long b) -> unsigned long long {
            unsigned long long ans = 0;
            while (b > 0) {
                if (b & 1) {  // 如果 b 的最后一位是1，结果可以加上 a
                    ans += a;
                }
                a += a;  // a 乘 2
                b >>= 1; // b 右移一位
            }
            return ans;
        };
        
        for (auto& s : strs) {
            unsigned long long key = 1;
            for (char c : s) {
                int idx = c - 96; // 字符减去 'a'，保证从0开始索引 prime 数组
                key = mul(key, prime[idx]); // 使用快速乘法
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