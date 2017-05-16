class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ret(2,-1);
        int L = 0, R = nums.size()-1;
        int pos = -1;
        while(L <= R)
        {
            int mid = L + (R - L)/2;
            if(target == nums[mid])
            {
                pos = mid;
                R = mid - 1;
            }
            else if(nums[mid] > target)
            {
                R = mid - 1;
            }
            else
            {
                L = mid + 1;
            }
        }
        if(pos == -1)return ret;
        ret[0] = pos;
        while(pos < nums.size() && nums[pos] == target)
        {
            pos++;
        }
        ret[1] = pos-1;
        return ret;
        
    }
};