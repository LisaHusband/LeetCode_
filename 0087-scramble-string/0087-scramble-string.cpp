#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    unordered_map<string, bool> sta; // 记忆化存储

    bool check(char* s1, char* s2, int len) {
        if (len <= 1) {
            return *s1 == *s2;
        }

        string key(s1, len);
        key += string(s2, len);

        if (sta.find(key) != sta.end()) {
            return sta[key];
        }

        // from left to right
        vector<int> mem(256, 0); // 使用一个数组代替unordered_map
        for (int i = 0; i < len; ++i) {
            mem[s1[i]]++;
            mem[s2[i]]--;

            bool is_valid = true;
            for (int j = 0; j < 256; ++j) {
                if (mem[j] != 0) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                if (i != len - 1) {
                    if (check(s1, s2, i + 1) && check(s1 + i + 1, s2 + i + 1, len - i - 1)) {
                        sta[key] = true;
                        return true;
                    }
                }
            }
        }

        // from right to left
        fill(mem.begin(), mem.end(), 0); // 清空计数器
        for (int i = 0; i < len; ++i) {
            mem[s1[i]]++;
            mem[s2[len - i - 1]]--;

            bool is_valid = true;
            for (int j = 0; j < 256; ++j) {
                if (mem[j] != 0) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                if (i != len - 1) {
                    if (check(s1, s2 + len - i - 1, i + 1) && check(s1 + i + 1, s2, len - i - 1)) {
                        sta[key] = true;
                        return true;
                    }
                }
            }
        }

        sta[key] = false;
        return false;
    }

    bool isScramble(string ss1, string ss2) {
        if (ss1.size() != ss2.size()) {
            return false;
        }
        
        return check(&ss1[0], &ss2[0], ss1.size());
    }
};
