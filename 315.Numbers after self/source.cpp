class Solution {
public:
    void modi(int cd, int idx, vector<int>& nums, vector<int> &xx)
    {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(cd <= nums[i])break;
            cnt++;
        }
        xx[idx] += cnt;
    }
    
    vector<int> helper(vector<int>& nums)
    {
        if(nums.empty())return vector<int>();
        if(nums.size() == 1)return vector<int>(1,0);
        
        int sz = nums.size()/2;
        vector<int>x(nums.begin(), nums.begin()+sz);
        vector<int>y(nums.begin()+sz,nums.end());
        vector<int>xx = helper(x);
        vector<int>yy = helper(y);
        sort(y.begin(),y.end());
        
        for(int i=0; i<x.size(); i++)
        {
            modi(x[i],i,y,xx);
        }
        xx.insert(xx.end(),yy.begin(),yy.end());
        return xx;
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        return helper(nums);
    }
};