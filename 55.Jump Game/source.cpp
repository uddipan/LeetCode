class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.empty())return true;
        int R = 0;
        int u = 0;
        while( u<nums.size() && u<=R)
        {
            R = max(R, u+nums[u]);
            if(R >= nums.size()-1)return true;
            u++;
        }
        return false;
    }
};