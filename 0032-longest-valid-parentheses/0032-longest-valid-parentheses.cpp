class Solution {
public:
    int longestValidParentheses(string s) {
        // 栈初始化，栈底用 -1 作为标记，方便计算长度
        stack<int> stk;
        stk.push(-1);  
        int maxLength = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                // 左括号入栈，记录索引
                stk.push(i);
            } else {
                // 右括号，弹出栈顶元素
                stk.pop();
                
                if (stk.empty()) {
                    // 如果栈空，说明没有匹配的左括号，重置栈，记录当前右括号的索引
                    stk.push(i);
                } else {
                    // 计算当前有效括号子串的长度
                    maxLength = max(maxLength, i - stk.top());
                }
            }
        }
        
        return maxLength;
    }
};