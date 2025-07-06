#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    // 快速乘法：用位运算加速乘法过程
    unsigned long long mul(unsigned long long a, unsigned long long b) {
        unsigned long long ans = 0; // 定义一个返回值
        while (b > 0) {
            if (b & 1) {  // 如果 b 的当前位为 1
                ans += a; // 将 a 加到 ans
            }
            a += a;  // a 乘 2
            b >>= 1; // b 右移一位
        }
        return ans;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // 每个字母对应一个质数，a 对应 107，b 对应 3，... 按顺序
        vector<int> prime = {107, 3, 2, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59,
                             61, 67, 71, 73, 79, 83, 89, 97, 101, 103};

        unordered_map<unsigned long long, vector<string>> hash;

        for (auto& s : strs) {
            unsigned long long key = 1;
            for (char c : s) {
                int idx = c - 96;  // 字符减去 'a'，保证从 0 开始索引 prime 数组
                key = mul(key, prime[idx]); // 使用快速乘法
            }
            hash[key].push_back(s); // 将字符串按 key 存入哈希表
        }

        vector<vector<string>> result;
        for (auto& p : hash) {
            result.push_back(move(p.second)); // 将结果按哈希表的值存入结果中
        }

        return result; // 返回最终的结果
    }
};

