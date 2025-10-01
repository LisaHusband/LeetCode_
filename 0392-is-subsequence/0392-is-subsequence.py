class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if s in t:
            return True
        else:
            in_num = 0
            in_index = 0
            for i in s:
                for j in range(len(t)):
                    if i==t[j]:
                        in_num+=1
                        in_index = j
                        break
                    else:
                        continue
                t = t[in_index+1:]
            if in_num==len(s):
                return True
            else:
                return False