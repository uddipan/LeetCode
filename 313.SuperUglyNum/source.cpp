class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(primes.empty())return 1;
        if(n == 1)return 1;
        map<int,int>M;
        vector<vector<int>>V;
        for(int i=0; i<primes.size(); i++)
        {
            V.push_back(vector<int>(1,primes[i]));
            M[primes[i]] = i;
        }
        
        int ret = 1;
        for(int i=2; i<=n; i++)
        {
            ret = (M.begin()->first);
            int idx = M.begin()->second;
            M.erase(M.begin());
            V[idx].erase(V[idx].begin());
            for(int j=idx; j<V.size(); j++)
            {
                V[j].push_back(ret*primes[j]);
            }
            M[V[idx][0]] = idx;
        }
        return ret;
    }
};