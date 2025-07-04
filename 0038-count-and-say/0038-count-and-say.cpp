class Solution {
public:
    string countAndSay(int n) {
        string num = "1";  // 初始数列为 "1"
        
        // 生成第 n 项数列
        for (int i = 1; i < n; i++) {
            string new_num = "";  // 用来存储当前轮次生成的数列
            int count = 1;  // 计数器
            
            // 遍历当前数列
            for (int j = 1; j < num.length(); j++) {
                // 如果当前字符和前一个字符相同，计数器增加
                if (num[j] == num[j - 1]) {
                    count++;
                } else {
                    // 如果字符不同，把计数和字符拼接到 new_num
                    new_num += to_string(count) + num[j - 1];
                    count = 1;  // 重置计数器
                }
            }
            
            // 处理最后一组数字
            new_num += to_string(count) + num.back();
            
            // 更新 num 为新的数列
            num = new_num;
        }
        
        return num;
    }
};