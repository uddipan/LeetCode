class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.empty())return 0;
        int L = 0, R = nums.size()-1, mid;
        while(L < R)
        {
            mid = (L + R)/2;
            if(nums[mid] < nums[mid+1])
            {
                L = mid + 1;
            }
            else
            {
                R = mid;
            }
        }
        return L;
    }
};