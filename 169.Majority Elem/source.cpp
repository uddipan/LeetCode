class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.empty())return 0;
        int idx = 0, cnt = 1;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[idx] == nums[i])
            {
                cnt++;
            }
            else
            {
                cnt --;
                if(cnt == 0)
                {
                    cnt = 1;
                    idx =  i;
                }
            }
        }
        return nums[idx];
    }
};