class Solution {
public:
    
    bool helper(string &s1, string &s2, string &s3)
    {
        int a = atoi(s1.c_str()), b = atoi(s2.c_str());
        for(int i=0; i<s3.size(); i++)
        {
            string s4 = s3.substr(0,i+1);
            if(s4.size() > 1 && s4[0] == '0')continue;
            string s5 = s3.substr(i+1);
            int c = atoi(s4.c_str());
            if(a+b == c && (s5.empty() || helper(s2,s4,s5)))
            {
                return true;
            }
        }
        return false;
    }
    
    bool isAdditiveNumber(string num) {
        if(num.size()<3)return false;
        
        for(int i=0; i<num.size(); i++)
        {
            string s1 = num.substr(0,i+1);
            if(s1.size() > 1 && s1[0] == '0')continue;
            for(int j=i+1; j<num.size(); j++)
            {
                string s2 = num.substr(i+1,j-i);
                if((s2.size() > 1 && s2[0] == '0') || s2.empty())continue;
                string s3 = num.substr(j+1);
                if(s3.empty())continue;
                if(helper(s1,s2,s3))
                {
                    return true;
                }
            }
        }
        return false;
    }
};