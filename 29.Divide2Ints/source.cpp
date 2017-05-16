class Solution {
public:
    
    int divide(int dividend, int divisor) {
        long sgn = 1;
        long A = long(dividend),B=long(divisor);
        if(A < 0)
        {
            A = -A;
            sgn *=-1;
        }
        if(B < 0)
        {
            B = -B;
            sgn *= -1;
        }
        
        long q = 0;
        long k = 0;
        
        while(A >= B)
        {
            k = 0;
            while(pow(2,k)*B <= A)
            {
                k++;
            }
            k--;
            q += (1UL<<k);
            A -= pow(2,k)*B;
        }
        if(q*sgn > INT_MAX)return INT_MAX;
        return int(q*sgn);
    }
    
};