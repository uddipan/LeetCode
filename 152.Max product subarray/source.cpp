class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.empty())return 0;
        int prevMin = nums[0], prevMax = nums[0],currMin=nums[0], currMax=nums[0], ret = nums[0];
        
        for(int i=1; i<nums.size(); i++)
        {
            currMax = max(max(nums[i], prevMax*nums[i]), prevMin*nums[i]);
            currMin = min(min(nums[i], prevMax*nums[i]), prevMin*nums[i]);
            ret = max(ret, max(currMax, currMin));
            prevMax = currMax;
            prevMin = currMin;
        }
        return ret;
    }
};