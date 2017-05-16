class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sumend = nums[0], maxsum = nums[0];
        for(auto i=1; i<nums.size(); i++)
        {
            sumend = max(sumend + nums[i], nums[i]);
            maxsum = max(sumend, maxsum);
        }
        return maxsum;
    }
};