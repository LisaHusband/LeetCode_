class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> chr_l;
        
        if (digits.empty()) {
            return result;
        }

        // 处理单个数字的情况
        if (digits.size() == 1) {
            int num = digits[0] - '0'; // 将字符转换为数字
            if (num < 7) {
                for (int i = 0; i < 3; i++) {
                    result.push_back(string(1, char((97 + (num - 2) * 3) + i)));
                }
            } else if (num == 7) {
                for (int i = 0; i < 4; i++) {
                    result.push_back(string(1, char(112 + i)));
                }
            } else if (num == 8) {
                for (int i = 0; i < 3; i++) {
                    result.push_back(string(1, char(116 + i)));
                }
            } else if (num == 9) {
                for (int i = 0; i < 4; i++) {
                    result.push_back(string(1, char(119 + i)));
                }
            }
            return result;
        }

        // 对多个数字进行处理
        for (char d : digits) {
            string all_chr = "";
            int num = d - '0'; // 将字符转换为数字
            if (num < 7) {
                for (int i = 0; i < 3; i++) {
                    all_chr += char((97 + (num - 2) * 3) + i);
                }
            } else if (num == 7) {
                for (int i = 0; i < 4; i++) {
                    all_chr += char(112 + i);
                }
            } else if (num == 8) {
                for (int i = 0; i < 3; i++) {
                    all_chr += char(116 + i);
                }
            } else if (num == 9) {
                for (int i = 0; i < 4; i++) {
                    all_chr += char(119 + i);
                }
            }
            chr_l.push_back(all_chr);
        }

        // 根据输入的数字组合出所有可能的字母组合
        if (chr_l.size() == 2) {
            for (char c : chr_l[0]) {
                for (char sub_ : chr_l[1]) {
                    result.push_back(string(1, c) + sub_);
                }
            }
        } else if (chr_l.size() == 3) {
            for (char c : chr_l[0]) {
                for (char sub_ : chr_l[1]) {
                    for (char ss : chr_l[2]) {
                        result.push_back(string(1, c) + sub_ + ss);
                    }
                }
            }
        } else if (chr_l.size() == 4) {
            for (char c : chr_l[0]) {
                for (char sub_ : chr_l[1]) {
                    for (char ss : chr_l[2]) {
                        for (char sss : chr_l[3]) {
                            result.push_back(string(1, c) + sub_ + ss + sss);
                        }
                    }
                }
            }
        }

        return result;
    }
};