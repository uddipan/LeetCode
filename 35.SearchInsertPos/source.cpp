class Solution {
public:
    int binMod(vector<int>& nums, int start, int end, int target)
    {
        if (start >= end)
        {
            if(nums[start] >= target)
            {
                return start;
            }
            else
            {
                return start + 1;
            }
        }
        int mid = (start + end)/2;
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[mid] > target)
        {
            return binMod(nums, start, mid, target);
        }
        else
        {
            return binMod(nums, mid+1, end, target);
        }
        
    }
    int searchInsert(vector<int>& nums, int target) {
        return binMod(nums, 0, nums.size()-1, target);
    }
};