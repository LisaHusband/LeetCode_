#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    unordered_map<string, bool> memo;

    // 拼接两个字符串作为key
    string makeKey(const string& s1, const string& s2) {
        return s1 + "#" + s2;
    }

public:
    bool isScramble(string s1, string s2) {
        return partly(s1, s2);
    }

    bool partly(const string& s1_part, const string& s2_part) {
        string key = makeKey(s1_part, s2_part);
        if (memo.count(key)) return memo[key];

        if (s1_part == s2_part) {
            memo[key] = true;
            return true;
        }

        // 字符异序快速剪枝
        string sorted_s1 = s1_part, sorted_s2 = s2_part;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        if (sorted_s1 != sorted_s2) {
            memo[key] = false;
            return false;
        }

        int n = s1_part.size();
        for (int i = 1; i < n; i++) {
            // 交换情况
            if (partly(s1_part.substr(0, i), s2_part.substr(n - i, i)) &&
                partly(s1_part.substr(i), s2_part.substr(0, n - i))) {
                memo[key] = true;
                return true;
            }
        }

        for (int i = 1; i < n; i++) {
            // 不交换情况
            if (partly(s1_part.substr(0, i), s2_part.substr(0, i)) &&
                partly(s1_part.substr(i), s2_part.substr(i))) {
                memo[key] = true;
                return true;
            }
        }

        memo[key] = false;
        return false;
    }
};