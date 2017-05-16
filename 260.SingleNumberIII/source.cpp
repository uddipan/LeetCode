class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int>V;
        if(nums.empty())return V;
        int a = 0;
        for(int i=0; i<nums.size(); i++)
        {
            a ^= nums[i];
        }
        //find a set bit
        int b = 0;
        while(a && (((a >> b)&1) == 0))
        {
            b++;
        }
        //find the # with bth bit set
        int c = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if((nums[i] >> b)&1)
            {
                c ^= nums[i];
            }
        }
        V.push_back(c);
        V.push_back(c^a);
        return V;
    }
};