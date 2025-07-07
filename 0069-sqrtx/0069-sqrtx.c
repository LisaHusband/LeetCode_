int mySqrt(int x){
    double s = x;
    __asm__ (
            "movq %1, %%xmm0;"
            "sqrtsd %%xmm0, %%xmm1;"
            "movq %%xmm1, %0"
            :"+r"(s)
            :"r"(s)
            );
    return s;
}