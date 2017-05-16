class Solution {
public:
    int *F;
    int fibo(int n)
    {
        if(F[n] != -1)return F[n];
        F[n] = fibo(n-1) + fibo(n-2);
        return F[n];
    }
    int climbStairs(int n) {
        F = new int[n+1];
        for(int i=0; i<=n; i++)F[i]=-1;
        F[0] = 1;
        F[1] = 1;
        F[2] = 2;
        return fibo(n);
    }
};