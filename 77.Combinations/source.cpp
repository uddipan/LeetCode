class Solution {
public:
    vector<vector<int>>res;
    void helper(vector<int>nums, vector<int>comb, int &k)
    {
        if(k == comb.size())
        {
            res.push_back(comb);
            return;
        }
        for(int i=0; i<nums.size(); i++)
        {
            vector<int>x(comb), y(nums.begin()+i+1,nums.end());
            x.push_back(nums[i]);
            helper(y,x,k);
        }
    }
    vector<vector<int>> combine(int n, int k) {
        if(k > n)return res;
        vector<int>nums;
        for(int i=1; i<=n; i++)nums.push_back(i);
        vector<int>comb;
        helper(nums, comb, k);
        return res;
    }
};