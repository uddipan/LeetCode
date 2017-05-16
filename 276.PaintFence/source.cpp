class Solution {
public:
    int numWays(int n, int k) {
        if(n == 0)return 0;
        if(n == 1)return k;
        if(n == 2)return k*k;
        
        int fsame = k, fdiff = k*(k-1);
        
        // https://leetcode.com/discuss/71756/explanation-of-dp-o-n-time-complexity-o-1-space-complexity
        // fsame(n + 1) = fdiff(n)
        // fdiff(n + 1) = (fsame(n) + fdiff(n)) * (k - 1)
        for(int i = 2; i<n; i++)
        {
            int tmp = fsame;
            fsame = fdiff;
            fdiff = (tmp + fdiff)*(k-1);
        }
        return fsame + fdiff;
    }
};