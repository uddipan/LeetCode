class Solution {
public:
    int binMod(vector<int> &nums, int l, int r)
    {
        if(l >= r)return nums[l];
        if(nums[l] < nums[r])return nums[l];
        int mid = (l + r)/2;
        if(nums[mid] > nums[r])
        {
            return binMod(nums, mid+1, r);
        }
        else
        {
            return binMod(nums, l, mid);
        }
    }
    int findMin(vector<int>& nums) {
        return binMod(nums, 0, nums.size()-1);
    }
};