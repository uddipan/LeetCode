class Solution {
public:
    vector<vector<int>> res;
    void helper(vector<int> comb, vector<int>nums, int sum, int k)
    {
        if(sum < 0 || comb.size() > k)return;
        if(sum == 0 && comb.size() == k)
        {
            res.push_back(comb);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>x(comb),y(nums.begin()+i+1, nums.end());
            x.push_back(nums[i]);
            helper(x,y,sum-nums[i],k);
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>nums;
        for(int i=1; i<=9; i++)
        {
            nums.push_back(i);
        }
        vector<int>comb;
        helper(comb,nums,n,k);
        return res;
    }
};