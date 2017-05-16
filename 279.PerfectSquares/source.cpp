class Solution {
public:
    vector<int>cache;
    int DP(int n)
    {
        if(cache[n] != -1)return cache[n];
        int tmp = INT_MAX;
        for(int i=1; i*i <= n; i++)
        {
            tmp = min(tmp, DP(n - i*i) + 1);
        }
        cache[n] = tmp;
        return tmp;
    }
    
    int numSquares(int n) {
        cache = vector<int>(n+1, -1);
        cache[0] = 0;
        cache[1] = 1;
        return DP(n);
    }
};