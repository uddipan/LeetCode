class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty())return false;
        multiset<int>M;
        
        for(int i=0; i<nums.size(); i++)
        {
            auto x = M.lower_bound(nums[i] - t);
            if(x != M.end() && (*x - nums[i]) <= t)
            {
                return true;
            }
            M.insert(nums[i]);
            if(M.size() > k)
            {
                M.erase(nums[i-k]);
            }
        }
        return false;
    }
};