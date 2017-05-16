class Solution {
public:
    bool isPalindrome(vector<vector<int>> &isPalin, int i, int j, string &s)
    {
        if(i > j)return true;
        if(isPalin[i][j] != -1)return isPalin[i][j];
        if(i == j)
        {
            isPalin[i][j] = 1;
            return true;
        }
        
        isPalin[i][j] = (s[i] == s[j] && isPalindrome(isPalin, i+1, j-1, s));
        return isPalin[i][j];
    }
    
    int minCut(string s) {
        if(s.empty())return 0;
        vector<vector<int>>isPalin(s.size(), vector<int>(s.size(),-1));
        vector<int>cache(s.size(),s.size()-1);
        cache[0] = 0;
        
        for(int i=0; i<s.size(); i++)
        {
            if(isPalindrome(isPalin,0,i,s))
            {
                cache[i] = 0;
                continue;
            }
            for(int j=0; j<i; j++)
            {
                if(isPalindrome(isPalin,j+1,i,s))
                {
                    cache[i] = min(cache[i], cache[j] + 1);
                }
            }
        }
        return cache[s.size()-1];
    }
    
    
};