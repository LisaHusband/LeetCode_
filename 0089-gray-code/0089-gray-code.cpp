#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
        generateGrayCodeRecursive(n, result);
        return result;
    }

private:
    void generateGrayCodeRecursive(int n, vector<int>& result) {
        if (n == 0) {
            result.push_back(0); // 基本情况：0位格雷码是[0]
            return;
        }

        generateGrayCodeRecursive(n - 1, result);  // 递归生成 n-1 位的格雷码

        int size = result.size();
        int addBit = 1 << (n - 1);  // 当前位的值是2^(n-1)

        // 反转原序列并加上当前位
        for (int i = size - 1; i >= 0; --i) {
            result.push_back(result[i] | addBit);  // 将当前位加到原序列中
        }
    }
};

