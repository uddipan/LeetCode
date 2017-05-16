class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0;
        int steps = 0;
        while(start < nums.size()-1)
        {
            steps++;
            if(nums[start] + start >= nums.size() -1)
            {
                return steps;
            }
            int maxLen = 0, idx = 0;
            for(int i=1; i<=nums[start]; i++)
            {
                if(maxLen < nums[start+i] + i)
                {
                    maxLen = max(maxLen, nums[start+i] + i);
                    idx = start + i;
                }
            }
            start = idx;
        }
        return steps;
    }
};