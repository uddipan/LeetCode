class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        if(nums.empty())return vector<int>();
        int ca = 0,cb = 0;
        int a = nums[0],b = nums[0];
        
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == a )
            {
                ca++;
            }
            else if(nums[i] == b )
            {
                cb++;
            }
            else if(ca == 0)
            {
                a = nums[i];
                ca = 1;
            }
            else if(cb == 0)
            {
                b = nums[i];
                cb = 1;
            }
            else
            {
                ca--;
                cb--;
            }
        }
        
        ca=0;cb=0;
        vector<int>res;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == a)ca++;
            else if(nums[i] == b)cb++;
        }
        if(ca > nums.size()/3)res.push_back(a);
        if(cb > nums.size()/3)res.push_back(b);
        return res;
    }
};