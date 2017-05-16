class Solution {
public:
    int trap(vector<int>& nums) {
        int accum = 0;
        
        int highest = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] < highest)
            {
                accum += highest - nums[i];
            }
            highest = max(highest, nums[i]);
        }
        int prehighest = highest;
        highest = 0;
        for(int i=nums.size()-1; i>=0; i--)
        {
            highest = max(highest, nums[i]);
            if(highest < prehighest) accum -=prehighest-highest;
        }
        return accum;
    }
};