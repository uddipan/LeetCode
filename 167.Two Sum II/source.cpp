class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>V;
        if(nums.empty())return V;
        int idx1 = 0, idx2 = nums.size()-1;
        
        while(idx1 < idx2)
        {
            if(nums[idx1] + nums[idx2] == target)
            {
                V.push_back(idx1+1);
                V.push_back(idx2+1);
                return V;
            }
            else if(nums[idx1] + nums[idx2] > target )
            {
                idx2--;
            }
            else
            {
                idx1++;
            }
        }
        return V;
    }
};