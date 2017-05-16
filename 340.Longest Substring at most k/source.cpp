class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if(s.empty() || k == 0)return 0;
        map<char,int>M;
        int u=0;
        int start = 0, cnt = 1;
        while(u < s.size())
        {
            if(M.find(s[u]) == M.end())
            {
                M[s[u]] = 1;
            }
            else
            {
                M[s[u]]++;
            }
            if(M.size() > k)
            {
                cnt = max(cnt, u-start);
                for(int i=start; i<=u; i++)
                {
                    M[s[i]]--;
                    if(M[s[i]] == 0)
                    {
                        M.erase(s[i]);
                        start = i+1;
                        break;
                    }
                }
            }
            u++;
        }
        cnt = max(cnt, u-start);
        return cnt;
    }
};