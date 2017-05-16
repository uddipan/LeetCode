class Solution {
public:
    
    int maximumGap(vector<int>& nums) {
        /* int mini = INT_MAX, maxi = INT_MIN;
         for(auto i=0; i<nums.size(); i++)
         {
         mini = min(mini, nums[i]);
         maxi = max(maxi, nums[i]);
         }
         int *p = new int[maxi - mini + 1];*/
        set<int>S;
        for(auto i=0; i<nums.size(); i++)
        {
            S.insert(nums[i]);
        }
        if(S.size() < 2)return 0;
        int diff = 0;
        auto it = S.begin(), it2 = next(it,1);
        while(it2 != S.end())
        {
            diff = max(diff,(*it2) - (*it));
            ++it2;
            ++it;
        }
        return diff;
    }
};