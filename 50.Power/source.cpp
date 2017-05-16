class Solution {
public:
    double power(double x, long n)
    {
        if(n == 0)return 1;
        if(n == 1)return x;
        if(x == 0)return 0;
        if(x == 1)return 1;
        
        if(n%2 == 0)
        {
            double y = power(x, n/2);
            return y*y;
        }
        else
        {
            return x*power(x,n-1);
        }
    }
    
    double myPow(double x, int n) {
        long m = abs(long(n));
        return (n >= 0)?power(x,m):1/power(x,m);
    }
};