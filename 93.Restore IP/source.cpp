class Solution {
public:
    vector<string>res;
    bool isValid(string s)
    {
        if(s.empty())return false;
        if(s.size()>3)return false;
        if(s.size() > 1 && s[0] == '0')return false;
        int x = atoi(s.c_str());
        return (x<256);
    }
    
    void helper(string s, int rem, string comb)
    {
        if(rem == 1)
        {
            if(isValid(s))
            {
                comb += s;
                res.push_back(comb);
            }
            return;
        }
        for(int i=0; i<3; i++)
        {
            if(i >= s.size())continue;
            string tmp = s.substr(0,i+1);
            if(tmp.size() > 1 && tmp[0] == '0')continue;
            if(isValid(tmp))
            {
                helper(s.substr(i+1),rem-1,comb+tmp+".");
            }
        }
    }
    
    vector<string> restoreIpAddresses(string s) {
        helper(s,4,"");
        return res;
    }
};