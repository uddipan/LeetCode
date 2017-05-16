class Solution {
public:
    map<string,int>cache;
    int helper(string s)
    {
        if(s.empty())return 1;
        if(cache.find(s) != cache.end())return cache[s];
        if(s[0] == '0')return 0;
        if(s.size() == 1)return 1;
        string s2 = (s.substr(0,2));
        int tmp = atoi(s2.c_str());
        cache[s] = helper(s.substr(1));
        if(tmp <= 26)cache[s] += helper(s.substr(2));
        return cache[s];
    }
    
    int numDecodings(string s) {
        if(s.empty())return 0;
        return helper(s);
    }
};