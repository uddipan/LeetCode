class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty())return;
        int u = nums.size() - 2;
        int idx = u + 1;
        
        while((u >= 0) && (nums[u] >= nums[u+1]))
        {
            u -- ;
        }
        if(u == -1)
        {
            sort(nums.begin(), nums.end());
            return;
        }
        idx = u;
        for(int i = nums.size()-1; i>idx; i--)
        {
            if(nums[idx] < nums[i])
            {
                int tmp = nums[idx];
                nums[idx] = nums[i];
                nums[i] = tmp;
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};