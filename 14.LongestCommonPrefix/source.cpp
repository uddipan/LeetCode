class Solution {
public:
    string pref(string s, string t)
    {
        string ret;
        unsigned u=0,v=0;
        while((u<s.size()) && (v<t.size()))
        {
            if(s[u] == t[v])ret.push_back(s[u]);
            else return ret;
            u++;v++;
        }
        return ret;
    }
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return string();
        if(strs.size() < 2)return strs[0];
        string prefix = strs[0];
        for(auto i=1; i<strs.size(); i++)
        {
            prefix = pref(prefix,strs[i]);
            if(prefix.empty())return prefix;
        }
        return prefix;
    }
};