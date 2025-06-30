class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len = 0, left = 0;
        bitset<128> seen;

        for (int right = 0; right < s.length(); ++right) {
            while (seen[s[right]]) {
                seen[s[left++]] = 0;
            }
            seen[s[right]] = 1;
            max_len = max(max_len, right - left + 1);
        }
        return max_len;
    }
    
};