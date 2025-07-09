class Solution:
    def isScramble(self, ss1: str, ss2: str) -> bool:

        sta = {} # 记忆化存储

        def check(s1=ss1, s2=ss2):
            if len(s1) != len(s2):
                return False
            if len(s1) <= 1:
                return s1 == s2
            
            if (s1, s2) in sta:
                return sta[s1, s2]

            # from left to right
            mem = {}
            for i in range(len(s1)):
                if s1[i] not in mem:
                    mem[s1[i]] = 1
                else:
                    mem[s1[i]] += 1
                    if mem[s1[i]] == 0:
                        mem.pop(s1[i])
                
                if s2[i] not in mem:
                    mem[s2[i]] = -1
                else:
                    mem[s2[i]] -= 1
                    if mem[s2[i]] == 0:
                        mem.pop(s2[i])

                if len(mem) == 0:
                    if i != len(s1)-1:
                        if check(s1[:i+1], s2[:i+1]) and check(s1[i+1:], s2[i+1:]):
                            sta[s1, s2] = True
                            return True

            # from right to left
            mem = {}
            for i in range(len(s1)):
                if s1[i] not in mem:
                    mem[s1[i]] = 1
                else:
                    mem[s1[i]] += 1
                    if mem[s1[i]] == 0:
                        mem.pop(s1[i])
                    
                if s2[-i-1] not in mem:
                    mem[s2[-i-1]] = -1
                else:
                    mem[s2[-i-1]] -= 1
                    if mem[s2[-i-1]] == 0:
                        mem.pop(s2[-i-1])
                    
                if len(mem) == 0:
                    if i != len(s1)-1:
                        if check(s1[:i+1], s2[-i-1:]) and check(s1[i+1:], s2[:-i-1]):
                            sta[s1, s2] = True
                            return True
            sta[s1, s2] = False
            return False
            
        return check()

# 作者：Nrgeup
# 链接：https://leetcode.cn/problems/scramble-string/solutions/725200/ji-yi-hua-sou-suo-by-nrgeup-z0kv/
# 来源：力扣（LeetCode）
# 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。