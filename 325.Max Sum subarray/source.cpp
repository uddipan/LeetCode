class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        if(nums.empty())return 0;
        map<int,int>S;
        int sum = 0, len = 0;
        for(int u=0; u<nums.size(); u++)
        {
            sum += nums[u];
            if(sum == k)
            {
                len = max(len,u+1);
            }
            if(S.find(sum - k) != S.end())
            {
                len = max(len, u - S[sum-k]);
            }
            if(S.find(sum) == S.end())S[sum] = u;
        }
        return len;
    }
};