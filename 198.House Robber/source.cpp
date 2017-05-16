class Solution {
public:
    vector<int> cache;
    int rin(int pos, vector<int>&nums)
    {
        if(pos < 0)return 0;
        if(cache[pos] != -1)return cache[pos];
        cache[pos] = max(rin(pos-1, nums), rin(pos-2, nums) + nums[pos]);
        return cache[pos];
    }
    int rob(vector<int>& nums) {
        cache = vector<int>(nums.size(), -1);
        return rin(nums.size() - 1, nums);
    }
};