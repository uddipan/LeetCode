class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty())return 0;
        int actualPos = 1, desiredPos = 0;
        while(actualPos < nums.size())
        {
            if(nums[actualPos] != nums[desiredPos])
            {
                desiredPos++;
                nums[desiredPos] = nums[actualPos];
            }
            actualPos++;
        }
        return desiredPos + 1;
    }
};