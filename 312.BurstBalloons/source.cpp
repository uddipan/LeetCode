class Solution {
public:
    
    int maxCoins(vector<int>& nums) {
        if(nums.empty())return 0;
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>>cache(n+2,vector<int>(n+2,0));
        for(int len = 1; len <=n; len++)
        {
            for(int left = 1; left <= n-len+1; left++)
            {
                int right = left + len - 1;
                for(int k = left; k<=right; k++)
                {
                    cache[left][right] = max(cache[left][right], nums[left-1]*nums[k]*nums[right+1] + cache[left][k-1] + cache[k+1][right]);
                }
            }
        }
        return cache[1][n];
    }
};