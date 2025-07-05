#include <vector>
#include <iostream>
#include <string>
class Solution {
public:
    string multiply(string num1, string num2) {
        // 字符到数字的映射
        vector<int> result(num1.length() + num2.length(), 0);

        // 逆序遍历 num2（翻转 num2）
        for (int i = num2.length() - 1; i >= 0; --i) {
            for (int j = num1.length() - 1; j >= 0; --j) {
                // 当前位的乘积
                int mul = (num2[i] - '0') * (num1[j] - '0');
                
                // 当前位置 (i + j) 是积的低位，(i + j + 1) 是高位
                int p1 = i + j, p2 = i + j + 1;

                // 当前位的值
                int total = mul + result[p2];
                result[p2] = total % 10;
                result[p1] += total / 10; // 处理进位，放到上位
            }
        }

        // 将结果转为字符串并去除前导零
        string result_str = "";
        for (int num : result) {
            result_str += to_string(num);
        }

        // 去掉前导零
        size_t start = result_str.find_first_not_of('0');
        if (start == string::npos) {
            return "0";  // 结果是零
        }

        return result_str.substr(start);
    }
};