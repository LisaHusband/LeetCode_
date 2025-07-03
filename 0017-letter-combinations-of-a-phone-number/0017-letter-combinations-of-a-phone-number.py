class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        result = []
        chr_l = []
        if len(digits)==0:
            return []
        if len(digits)==1:
            num = int(digits)
            if num<7:
                for i in range(0,3):
                    result.append(chr((97+(num-2)*3)+i))
                return result
            elif num==7:
                for i in range(0,4):
                    result.append(chr(112+i))
                return result
            elif num==8:
                for i in range(0,3):
                    result.append(chr(116+i))
                return result
            elif num==9:
                for i in range(0,4):
                    result.append(chr(119+i))
                return result
        else:
            for d in digits:
                all_chr = ""
                num = int(d)
                if num<7:
                    for i in range(0,3):
                        all_chr+=(chr((97+(num-2)*3)+i))
                elif num==7:
                    for i in range(0,4):
                        all_chr+=(chr(112+i))
                elif num==8:
                    for i in range(0,3):
                        all_chr+=(chr(116+i))
                elif num==9:
                    for i in range(0,4):
                        all_chr+=(chr(119+i))
                chr_l.append(all_chr)
            
            if len(chr_l)==2:
                for c in chr_l[0]:
                    for sub_ in chr_l[1]:
                        result.append(str(c)+str(sub_))
            elif len(chr_l)==3:
                for c in chr_l[0]:
                    for sub_ in chr_l[1]:
                        for ss in chr_l[2]:
                            result.append(str(c)+str(sub_)+str(ss))
            else:
                for c in chr_l[0]:
                    for sub_ in chr_l[1]:
                        for ss in chr_l[2]:
                            for sss in chr_l[3]:
                                result.append(str(c)+str(sub_)+ str(ss)+ str(sss))
            return result

        
