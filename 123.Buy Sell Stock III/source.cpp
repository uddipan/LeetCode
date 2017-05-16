class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        vector<int>fwd,bkd;
        int minSoFar = INT_MAX;
        int profit = INT_MIN;
        
        for(int i=0; i<prices.size(); i++)
        {
            minSoFar = min(minSoFar, prices[i]);
            profit = max(profit, prices[i] - minSoFar);
            fwd.push_back(profit);
        }
        
        int maxSoFar = INT_MIN;
        profit = INT_MIN;
        
        for(int i=prices.size()-1; i>=0; i--)
        {
            maxSoFar = max(maxSoFar, prices[i]);
            profit = max(profit, maxSoFar - prices[i]);
            bkd.insert(bkd.begin(),profit);
        }
        
        profit = INT_MIN;
        for(int i=0; i<prices.size()-1; i++)
        {
            profit = max(profit, fwd[i] + bkd[i+1]);
        }
        profit = max(profit, bkd[0]);
        return profit;
    }
};