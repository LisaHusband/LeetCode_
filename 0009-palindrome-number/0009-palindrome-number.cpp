class Solution {
public:
    bool isPalindrome(int x) {
    if (x < 0) return false;
        string s = to_string(x);
        int n = s.size();

        if (n % 2 == 0) {
            string left = s.substr(0, n / 2);
            string right = s.substr(n / 2);
            reverse(right.begin(), right.end());
            return left == right;
        } else {
            string left = s.substr(0, n / 2);
            string right = s.substr(n / 2 + 1);
            reverse(right.begin(), right.end());
            return left == right;
        }
    }
};