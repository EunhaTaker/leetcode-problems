int divide(int dividend, int divisor) {
    if(dividend==(1<<31)){
        if(divisor==-1)
            return (1<<31)-1;
        else if(divisor==1)
            return dividend;
    }
    // 结果是否为负数
    int flag = (dividend>0)^(divisor>0);
    // 被除数、除数全部转化为负数
    if(dividend>0) dividend = 0-(dividend);
    if(divisor>0) divisor = 0-(divisor);
    int temp;   // 临时被除数
    int base;   // temp是divisor的base倍
    int quotient = 0;  // 
    while(dividend<=divisor){
        temp = divisor;base = 1;    // 初始化
        while(dividend-temp<=temp){
            // 临时被除数翻倍，负数不能用<<翻倍
            temp+=temp;
            base<<=1;
        }
        dividend -= temp;
        quotient += base;
    }
    if(flag) quotient = 0 - quotient;
    return quotient;
}