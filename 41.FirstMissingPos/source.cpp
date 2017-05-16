class Solution {
public:
    void swap(int &a, int &b)
    {
        int temp = a;
        a=b;
        b=temp;
    }
    int firstMissingPositive(vector<int>& nums) {
        auto u=0;
        while(u < nums.size())
        {
            if((nums[u] > 0) && (nums[u] <= nums.size()))
            {
                swap(nums[u], nums[nums[u] - 1]);
                if(nums[u] == nums[nums[u] - 1])u++;
            }
            else
            {
                u++;
            }
        }
        
        for(auto i=0; i<nums.size(); i++)
        {
            if(i + 1 != nums[i])
            {
                return i+1;
            }
        }
        return nums.size() + 1;
    }
};