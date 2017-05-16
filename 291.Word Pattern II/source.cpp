class Solution {
public:
    map<char,string>M;
    set<string>S;
    bool helper(string &pattern, string &str)
    {
        if(pattern.empty() && str.empty())return true;
        if(pattern.empty() || str.empty())return false;
        if(M.find(pattern[0]) != M.end())
        {
            string match = M[pattern[0]];
            if(match.size() > str.size())return false;
            string pot = str.substr(0,match.size());
            string np = pattern.substr(1), ns = str.substr(pot.size());
            return (pot == match && helper(np,ns));
        }
        else
        {
            for(int i=0; i<str.size(); i++)
            {
                string tmp = str.substr(0,i+1);
                if(S.find(tmp) != S.end())continue;
                M[pattern[0]] =tmp;
                S.insert(tmp);
                string np = pattern.substr(1), ns = str.substr(i+1);
                if(helper(np,ns))return true;
                M.erase(pattern[0]);
                S.erase(tmp);
            }
        }
        return false;
    }
    
    bool wordPatternMatch(string pattern, string str) {
        return helper(pattern, str);
    }
};