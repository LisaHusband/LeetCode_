#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
        unordered_map<string, bool> sta; // 记忆化存储

bool check(string s1, string s2) {
            if (s1.size() != s2.size()) {
                return false;
            }
            if (s1.size() <= 1) {
                return s1 == s2;
            }

            if (sta.find(s1 + s2) != sta.end()) {
                return sta[s1 + s2];
            }

            // from left to right
            unordered_map<char, int> mem;
            for (int i = 0; i < s1.size(); ++i) {
                mem[s1[i]]++;
                mem[s2[i]]--;

                bool is_valid = true;
                for (auto &entry : mem) {
                    if (entry.second != 0) {
                        is_valid = false;
                        break;
                    }
                }

                if (is_valid) {
                    if (i != s1.size() - 1) {
                        if (check(s1.substr(0, i + 1), s2.substr(0, i + 1)) && check(s1.substr(i + 1), s2.substr(i + 1))) {
                            sta[s1 + s2] = true;
                            return true;
                        }
                    }
                }
            }

            // from right to left
            mem.clear();
            for (int i = 0; i < s1.size(); ++i) {
                mem[s1[i]]++;
                mem[s2[s2.size() - i - 1]]--;

                bool is_valid = true;
                for (auto &entry : mem) {
                    if (entry.second != 0) {
                        is_valid = false;
                        break;
                    }
                }

                if (is_valid) {
                    if (i != s1.size() - 1) {
                        if (check(s1.substr(0, i + 1), s2.substr(s2.size() - i - 1)) && check(s1.substr(i + 1), s2.substr(0, s2.size() - i - 1))) {
                            sta[s1 + s2] = true;
                            return true;
                        }
                    }
                }
            }

            sta[s1 + s2] = false;
            return false;
        }
    bool isScramble(string ss1, string ss2) {

        

        return check(ss1, ss2);
    }
};
