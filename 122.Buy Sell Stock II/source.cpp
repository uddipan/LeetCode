class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty())return 0;
        int localmin = prices[0], localmax = prices[0], idx = 1;
        int profit = 0;
        
        while(idx < prices.size())
        {
            if(prices[idx] < prices[idx - 1])
            {
                profit += localmax - localmin;
                localmin = prices[idx];
                localmax = prices[idx];
            }
            else
            {
                localmax = prices[idx];
            }
            idx++;
        }
        profit += localmax - localmin;
        return profit;
    }
};