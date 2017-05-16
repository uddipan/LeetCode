class Solution {
public:
    vector<vector<int>>cache;
    bool helper(string &s, int start, int end, unordered_set<string>& wordDict)
    {
        if(start > end)return true;
        string S = s.substr(start, end-start+1);
        if(wordDict.find(S) != wordDict.end())return true;
        if(cache[start][end] != -1)return cache[start][end];
        
        for(int i=start; i<end; i++)
        {
            if(helper(s,start,i,wordDict) && helper(s,i+1,end,wordDict))
            {
                cache[start][end] = true;
                return true;
            }
        }
        cache[start][end] = false;
        return false;
    }
    
    bool wordBreak(string s, unordered_set<string>& wordDict) {
        cache = vector<vector<int>>(s.size(), vector<int>(s.size(),-1));
        return helper(s,0,s.size()-1,wordDict);
    }
};