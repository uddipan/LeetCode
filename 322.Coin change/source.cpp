class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)return 0;
        if(coins.empty())return -1;
        vector<int>dp(amount+1,-1);
        dp[0] = 0;
        for(int i=1; i<=amount; i++)
        {
            for(int j=0; j<coins.size(); j++)
            {
                int tmp = i - coins[j];
                if(tmp >= 0 && dp[tmp] != -1)
                {
                    if(dp[i] == -1)dp[i] = dp[tmp] + 1;
                    else dp[i] = min(dp[i], dp[tmp] + 1);
                }
            }
        }
        return dp[amount];
    }
};