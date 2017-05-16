class Solution {
public:
    string itoaM(int i)
    {
        string s;
        bool b = false;
        if(i < 0)
        {
            b = true;
            i = -i;
        }
        if(i == 0)
        {
            return "0";
        }
        while(i)
        {
            char c = char((i%10)) + '0';
            s.insert(s.begin(),c);
            i/=10;
        }
        if(b) s.insert(s.begin(), '-');
        return s;
    }
    
    string range(int lo, int hi)
    {
        string s;
        if(lo == hi)
        {
            s =  itoaM(lo) ;
        }
        else
        {
            s =  itoaM(lo) + "->" + itoaM(hi);
        }
        return s;
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string>V;
        if(nums.empty())
        {
            V.push_back(range(lower,upper));
            return V;
        }
        int lo,hi;
        if(lower < nums[0])
        {
            lo = lower;
            hi = nums[0] - 1;
            V.push_back(range(lo,hi));
        }
        for(int i=1 ; i<nums.size(); i++)
        {
            if((nums[i] - nums[i-1] > 1) && (nums[i-1] < upper))
            {
                int lo = nums[i-1]+1, hi = min(nums[i]-1,upper);
                V.push_back(range(lo,hi));
            }
        }
        if(upper > nums[nums.size()-1])
        {
            lo = nums[nums.size()-1] + 1;
            hi = upper;
            V.push_back(range(lo,hi));
        }
        return V;
    }
};