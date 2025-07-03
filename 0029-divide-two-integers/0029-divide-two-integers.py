class Solution:
    def divide(self, dividend: int, divisor: int) -> int:
        result=0
        symbol=1
        if divisor==0:
            return
        elif divisor==1:
            if abs(dividend)<2**31:
                return dividend
            elif dividend>0:
                return 2**31-1
            else:
                return -2**31
        elif divisor==-1:
            if abs(dividend)<2**31:
                return -dividend
            elif dividend>0:
                return -2**31
            else:
                return 2**31-1
        if dividend>0 and divisor>0:
            symbol=1
        elif divisor<0 and dividend<0:
            symbol=1
        elif divisor<0 or dividend<0:
            symbol=-1
        divisor=abs(divisor)
        dividend=abs(dividend)
        while dividend>=divisor:
            tmp = divisor
            mul = 1
            while dividend>=(tmp <<1):
                tmp <<=1
                mul <<=1
            dividend-=tmp
            result+=mul
            print([tmp,mul,dividend,result])
        
        if symbol<0:
            result= -result
        return result
        
