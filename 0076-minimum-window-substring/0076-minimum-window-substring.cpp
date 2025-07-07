class Solution {
public:
    int id(char c){
        return islower(c)?c-'a':c-'A'+26;
    }
    string minWindow(string s, string t) {
        int mp[52] = {0},less = 0;
        for(char c:t)
            if(--mp[id(c)]==-1)++less;
        int i=0,j=0;
        int start = 0,len = INT_MAX;
        while(j<s.length()){
            if(++mp[id(s[j])]==0&&--less==0){
                while(less==0&&i<=j)
                    if(--mp[id(s[i++])]==-1&&++less)
                        break;
                if(j-i+2<len){
                    start = i-1;
                    len = j-i+2;
                }
            }
            ++j;
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};