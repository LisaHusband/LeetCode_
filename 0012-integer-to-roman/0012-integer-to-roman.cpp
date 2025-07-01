class Solution {
public:
    string intToRoman(int num) {
        string result = "";

        // 剪枝：直接处理特殊减法情况
        if (num / 1000 > 0) {
            int thousands = num / 1000;
            for (int i = 0; i < thousands; ++i) {
                result += "M";
            }
            num %= 1000;
        }
        
        // 处理900的情况（CM）
        if (num / 900 > 0) {
            result += "CM";
            num -= 900;
        }

        // 处理500的情况（D）
        if (num / 500 > 0) {
            result += "D";
            num -= 500;
        }
        
        // 处理400的情况（CD）
        if (num / 400 > 0) {
            result += "CD";
            num -= 400;
        }
        
        // 处理100的情况（C）
        while (num >= 100) {
            result += "C";
            num -= 100;
        }

        // 处理90的情况（XC）
        if (num / 90 > 0) {
            result += "XC";
            num -= 90;
        }

        // 处理50的情况（L）
        if (num / 50 > 0) {
            result += "L";
            num -= 50;
        }
        
        // 处理40的情况（XL）
        if (num / 40 > 0) {
            result += "XL";
            num -= 40;
        }

        // 处理10的情况（X）
        while (num >= 10) {
            result += "X";
            num -= 10;
        }

        // 处理9的情况（IX）
        if (num / 9 > 0) {
            result += "IX";
            num -= 9;
        }

        // 处理5的情况（V）
        if (num / 5 > 0) {
            result += "V";
            num -= 5;
        }

        // 处理4的情况（IV）
        if (num / 4 > 0) {
            result += "IV";
            num -= 4;
        }

        // 处理1的情况（I）
        while (num >= 1) {
            result += "I";
            num -= 1;
        }

        return result;
    }
};