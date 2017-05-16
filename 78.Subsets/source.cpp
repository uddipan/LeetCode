class Solution {
public:
    vector<vector<int>> V;
    void helper(vector<int>&nums)
    {
        if(nums.empty())return;
        vector<int>A(nums.begin()+1,nums.end());
        helper(A);
        int sz = V.size();
        for(int i=0; i<sz; i++)
        {
            vector<int>tmp(V[i]);
            tmp.push_back(nums[0]);
            V.push_back(tmp);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty())return V;
        V.push_back(vector<int>());
        helper(nums);
        return V;
    }
};