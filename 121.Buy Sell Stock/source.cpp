class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int minSoFar = INT_MAX;
        int profit = INT_MIN;
        
        for(int i=0; i<prices.size(); i++)
        {
            minSoFar = min(minSoFar, prices[i]);
            profit = max(profit, prices[i] - minSoFar);
        }
        return profit;
    }
};