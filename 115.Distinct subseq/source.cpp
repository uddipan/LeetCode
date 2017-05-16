class Solution {
public:
    vector<vector<int>>cache;
    int helper(string &s, string &t, int i, int j)
    {
        if(j >= t.size())return 1;
        if(i >= s.size())return 0;
        if(cache[i][j] != -1)return cache[i][j];
        if(s[i] == t[j])
        {
            cache[i][j] = helper(s,t,i+1,j+1) + helper(s,t,i+1,j);
        }
        else
        {
            cache[i][j] = helper(s,t,i+1,j);
        }
        return cache[i][j];
    }
    
    int numDistinct(string s, string t) {
        cache = vector<vector<int>>(s.size(), vector<int>(t.size(),-1));
        return helper(s,t,0,0);
    }
};