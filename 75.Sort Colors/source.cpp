class Solution {
public:
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    void sortColors(vector<int>& nums) {
        if(nums.empty())return ;
        int L=0,M=0,R=nums.size();
        while(M<R)
        {
            if(nums[M] == 0)
            {
                swap(nums[M++],nums[L++]);
            }
            else if(nums[M] == 1)
            {
                M++;
            }
            else
            {
                swap(nums[M],nums[--R]);
            }
        }
    }
};