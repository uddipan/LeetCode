class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size() < 3)return 0;
        int cnt = 0;
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size() - 2; i++)
        {
            int j = i+1, k = nums.size()-1;
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] < target)
                {
                    cnt += k - j;
                    j++;
                }
                else
                {
                    k--;
                }
            }
        }
        return cnt;
    }
};