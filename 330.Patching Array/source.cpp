class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        long k = 1, idx = 0;
        int patch = 0;
        
        while(k <= n)
        {
            if(idx == nums.size() || nums[idx] > k)
            {
                k *=2;
                patch++;
            }
            else
            {
                k += nums[idx];
                idx++;
            }
        }
        return patch;
    }
};