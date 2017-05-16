class Solution {
public:
    int countPrimes(int n) {
        if(n < 2)return 0;
        vector<bool>cache(n+1,0);
        int cnt = 0;
        for(int i=2; i<n ; i++)
        {
            if(!cache[i])
            {
                cnt++;
                int k = i;
                while(k < n)
                {
                    cache[k] = true;
                    k +=i;
                }
            }
        }
        return cnt;
    }
};