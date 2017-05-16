class Solution {
public:
    bool isWin(string s)
    {
        for(int i=0; i<s.size()-1; i++)
        {
            if(s[i] == '+' && s[i+1] == '+')
            {
                string tmp(s);
                tmp[i] = '-';
                tmp[i+1] = '-';
                if(!isWin(tmp))return true;
            }
        }
        return false;
    }
    bool canWin(string s) {
        if(s.empty())return false;
        return isWin(s);
    }
};