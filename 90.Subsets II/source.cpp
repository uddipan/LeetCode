class Solution {
public:
    set<multiset<int>>res;
    void helper(vector<int>nums)
    {
        if(nums.empty())
        {
            return;
        }
        vector<int>x(nums.begin()+1,nums.end());
        helper(x);
        int sz = res.size();
        int cnt = 0;
        auto tmp = res;
        while(cnt < sz)
        {
            auto it = next(tmp.begin(),cnt);
            auto y = *it;
            y.insert(nums[0]);
            res.insert(y);
            cnt++;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>V;
        if(nums.empty())return V;
        res.insert(multiset<int>());
        helper(nums);
        for(auto it = res.begin(); it != res.end(); ++it)
        {
            auto x = *it;
            vector<int>tmp(x.begin(),x.end());
            V.push_back(tmp);
        }
        return V;
    }
};