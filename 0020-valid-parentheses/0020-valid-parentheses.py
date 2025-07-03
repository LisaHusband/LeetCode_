class Solution:
    def isValid(self, s: str) -> bool:
        symbol_l = []
        count=0
        if len(s)%2!=0:
            return False
        try:
            for i in s:
                if i in "({[":
                    symbol_l.append(i)
                    count+=1
                elif symbol_l[-1]+i in "(){}[]":
                    symbol_l.pop()
                
            return len(symbol_l)==0 and count==len(s)/2
        except:
            return False