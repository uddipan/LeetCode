class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int mask[32] = {0};
        int res = 0;
        for(unsigned u=0; u<nums.size(); u++)
        {
            for(int i=0; i<32; i++)
            {
                mask[i] += (nums[u] >> i) & 1;
                mask[i] %=3;
            }
            
        }
        int num = 0;
        int k = 1;
        for(int i=0; i<32; i++)
        {
            num += k*mask[i];
            k *= 2;
        }
        return num;
    }
};