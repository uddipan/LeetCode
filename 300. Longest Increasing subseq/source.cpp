class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())return 0;
        vector<int> len(nums.size(),1);
        int L = 1;
        for(auto i=0; i<nums.size(); i++)
        {
            for(auto j=0; j<i; j++)
            {
                if(nums[j] < nums[i])
                {
                    len[i] = max(len[i], len[j]+1);
                    L = max(L, len[i]);
                }
            }
        }
        return L;
    }
};