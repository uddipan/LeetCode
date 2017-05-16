class Solution {
public:
    vector<vector<int>>Cache;
    int helper(int n, int color, vector<vector<int>>& costs)
    {
        if(n < 0)return 0;
        if(Cache[n][color] != -1)return Cache[n][color];
        
        Cache[n][color] = costs[n][color] + min(helper(n-1,(color+1)%3,costs), helper(n-1,(color+2)%3,costs));
        return Cache[n][color];
    }
    int minCost(vector<vector<int>>& costs) {
        if(costs.empty())return 0;
        Cache = vector<vector<int>>(costs.size(), vector<int>(3,-1));
        Cache[0][0] = costs[0][0];
        Cache[0][1] = costs[0][1];
        Cache[0][2] = costs[0][2];
        int  n = costs.size();
        int res =  min(helper(n-1,0,costs), helper(n-1,1,costs));
        res = min(res, helper(n-1,2,costs));
        return res;
    }
};