class Solution {
public:
    vector<vector<int>>Cache;
    int helper(int n, int k, int color, vector<vector<int>>& costs)
    {
        if(n < 0)return 0;
        if(Cache[n][color] != -1)return Cache[n][color];
        
        Cache[n][color] = INT_MAX;
        for(int i=1; i<k; i++)
        {
            Cache[n][color] = min(Cache[n][color], helper(n-1, k, (color+i)%k, costs));
        }
        Cache[n][color] += costs[n][color];
        return Cache[n][color];
    }
    
    int minCostII(vector<vector<int>>& costs) {
        if(costs.empty())return 0;
        int  n = costs.size(), k = costs[0].size();
        Cache = vector<vector<int>>(costs.size(), vector<int>(k,-1));
        
        for(int i=0; i<k; i++)Cache[0][i] = costs[0][i];
        int res = INT_MAX;
        for(int i=0; i<k; i++)
        {
            res = min(res, helper(n-1,k,i,costs));
        }
        return res;
    }
};