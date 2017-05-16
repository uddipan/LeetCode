class Solution {
public:
    string itoaM(long n)
    {
        string s;
        if(n == 0)return "0";
        bool b = false;
        if(n < 0)
        {
            b = true;
            n = -n;
        }
        while(n)
        {
            s.insert(s.begin(),char(n%10) + '0');
            n/=10;
        }
        if(b) s.insert(s.begin(), '-');
        return s;
    }
    
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>V;
        if(nums.empty())return V;
        int L = 0, R = 0;
        for(int i=1; i<nums.size(); i++)
        {
            long A = long(nums[i]), B = long(nums[i-1]);
            if(A - B > 1)
            {
                string s;
                if( L == R)
                {
                    s = itoaM(long(nums[L]));
                }
                else
                {
                    s = itoaM(long(nums[L])) + "->" + itoaM(long(nums[R]));
                }
                L =i; R = i;
                V.push_back(s);
            }
            else
            {
                R++;
            }
        }
        if( L == R)
        {
            V.push_back(itoaM(long(nums[L])));
        }
        else
        {
            V.push_back(itoaM(long(nums[L])) + "->" + itoaM(long(nums[R])));
        }
        return V;
    }
};