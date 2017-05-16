class Solution {
public:
    set<vector<int>>res;
    void helper(vector<int>&nums, vector<int>&comb, int sum)
    {
        if(sum < 0)return;
        if(sum == 0)
        {
            sort(comb.begin(),comb.end());
            res.insert(comb);
            return;
        }
        
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>x(comb), y(nums.begin()+i+1, nums.end());
            x.push_back(nums[i]);
            helper(y,x,sum - nums[i]);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>final;
        if(candidates.empty())return final;
        vector<int>comb;
        helper(candidates, comb, target);
        for(auto it=res.begin(); it != res.end(); ++it)
        {
            final.push_back(*it);
        }
        return final;
    }
};