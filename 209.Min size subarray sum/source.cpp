class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.empty())return 0;
        int left = 0, right = 0, opt = INT_MAX, sum = nums[0];
        while(right < nums.size())
        {
            if(sum < s)
            {
                right ++;
                if(right == nums.size())break;
                sum += nums[right] ;
            }
            else
            {
                opt = min(opt,right - left + 1);
                sum -=nums[left];
                left ++;
                if(left == nums.size())break;
                if(left > right)
                {
                    sum = nums[left];
                    right = left;
                }
            }
        }
        if(opt == INT_MAX)return 0;
        return opt;
    }
};