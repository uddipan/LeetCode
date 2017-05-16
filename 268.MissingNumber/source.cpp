class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long X = 0,Y = 0;
        for (auto i =0; i<nums.size(); i++)
        {
            X += long(nums[i]);
        }
        int n = nums.size() ;
        Y = long(n)*long(n+1)/long(2);
        return int(Y-X);
    }
};