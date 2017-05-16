class Solution {
public:
    int helper(vector<int>&nums, int L, int R)
    {
        if(L == R)
        {
            return nums[L];
        }
        int mid = L + (R - L)/2;
        if(nums[mid] > nums[R])
        {
            return helper(nums, mid+1,R);
        }
        else if (nums[mid] < nums[R])
        {
            return helper(nums, L, mid);
        }
        else
        {
            int x = helper(nums, L, mid);
            int y = helper(nums, mid+1, R);
            if(x < y)return x;
            else return y;
        }
    }
    int findMin(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};