class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        if(nums.empty())return nums;
        vector<int>A(nums), B(nums);
        int prod = nums[0];
        A[0] = 1;
        B[B.size()-1] = 1;
        for(int i=1; i<nums.size(); i++)
        {
            A[i] = prod;
            prod *=nums[i];
        }
        prod = nums[nums.size()-1];
        for(int i=B.size()-2; i>=0; i--)
        {
            B[i] = prod;
            prod *=nums[i];
        }
        for(int i=0; i<nums.size(); i++)
        {
            A[i] = A[i]*B[i];
        }
        return A;
    }
};