class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        if(nums.empty())return 0;
        vector<long long>sum(nums.size()+1,0);
        sum[0] = nums[0];
        multiset<long long>M;
        for(int i=1; i<sum.size(); i++)
        {
            sum[i] += sum[i-1] + nums[i-1];
        }
        
        int count = 0;
        for(int i=sum.size()-1; i>0; i--)
        {
            M.insert(sum[i]);
            
            auto lb = M.lower_bound(lower + sum[i-1]);
            auto ub = M.upper_bound(upper + sum[i-1]);
            count += distance(lb,ub);
        }
        return count;
    }
};