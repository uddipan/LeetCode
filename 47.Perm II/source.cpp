class Solution {
public:
    set<vector<int>>res;
    void helper(vector<int>nums, vector<int>comb, int depth)
    {
        if(depth == 0)
        {
            res.insert(comb);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            if(i && nums[i] == nums[i-1])continue;
            vector<int>x(comb), y(nums.begin(),nums.end());
            y.erase(y.begin()+i);
            x.push_back(nums[i]);
            helper(y,x,depth-1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>final;
        if(nums.empty())return final;
        sort(nums.begin(),nums.end());
        vector<int>comb;
        helper(nums,comb,nums.size());
        for(auto it = res.begin(); it != res.end(); ++it)
        {
            final.push_back(*it);
        }
        return final;
    }
};