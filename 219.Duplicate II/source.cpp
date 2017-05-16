class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int,int>M;
        for(int i=0; i<nums.size(); i++)
        {
            if(M.find(nums[i]) == M.end())
            {
                M[nums[i]] = i;
            }
            else
            {
                if(i - M[nums[i]] <= k)return true;
                M[nums[i]] = i;
            }
        }
        return false;
    }
};