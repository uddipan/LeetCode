class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int L = 0, R = nums.size() - 1;
        while(L <= R)
        {
            int mid = L + (R - L)/2;
            if(target == nums[mid] || target == nums[L] || target == nums[R])return true;
            if(nums[mid] > nums[L])
            {
                // pivot on right
                if(target > nums[mid] || target < nums[L])
                {
                    L = mid + 1;
                }
                else
                {
                    R = mid;
                }
            }
            else if(nums[mid] < nums[L])
            {
                // pivot on left
                if(target < nums[mid] || target > nums[R])
                {
                    R = mid;
                }
                else
                {
                    L = mid + 1;
                }
            }
            else
            {
                while(nums[L] == nums[mid])L++;
                while(nums[R] == nums[mid])R--;
            }
        }
        return false;
    }
};