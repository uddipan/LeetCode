class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())return 0;
        int actualIndex = 0, desiredIndex = 0;
        while(actualIndex < nums.size())
        {
            if(nums[desiredIndex] != val)desiredIndex++;
            else if(nums[desiredIndex] == val && nums[actualIndex] != val)
            {
                swap(nums[desiredIndex++], nums[actualIndex]);
            }
            actualIndex++;
        }
        if(desiredIndex == 0 && nums[0] != val)return nums.size();
        return desiredIndex;
    }
};