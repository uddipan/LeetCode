class Solution {
public:
    bool valid(string s1, string s2, string s3)
    {
        if(s1.empty())return (s2 == s3);
        if(s2.empty())return (s1 == s3);
        if(s1.size() + s2.size() < s3.size())return false;
        
        int idx1 = 0, idx2 = 0, idx3 = 0;
        while(idx3 < s3.size())
        {
            if(idx1 > s1.size())
            {
                if(s2[idx2] != s3[idx3])return false;
                idx2++; idx3++;
            }
            else if(idx2 > s2.size())
            {
                if(s1[idx1] != s3[idx3])return false;
                idx1++; idx3++;
            }
            else
            {
                if(s3[idx3] != s1[idx1] && s3[idx3] != s2[idx2])return false;
                if(s1[idx1] == s2[idx2])
                {
                    return (valid(s1.substr(idx1), s2.substr(idx2+1), s3.substr(idx3+1)) |
                            valid(s1.substr(idx1+1), s2.substr(idx2), s3.substr(idx3+1)));
                }
                else if(s1[idx1] == s3[idx3])
                {
                    idx1++;idx3++;
                }
                else
                {
                    idx2++;idx3++;
                }
            }
        }
        return true;
    }
    bool isInterleave(string s1, string s2, string s3) {
        return valid(s1,s2,s3);
    }
};