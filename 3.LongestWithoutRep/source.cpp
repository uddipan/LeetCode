class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>M;
        int idx = 0, start = 0,len = 0;
        while(idx < s.size())
        {
            if(M.find(s[idx]) != M.end())
            {
                len = max(len, idx - start);
                for(int i=start; i<M[s[idx]]; i++)
                {
                    M.erase(s[i]);
                }
                start = M[s[idx]]+1;
            }
            M[s[idx]] = idx;
            idx++;
        }
        len = max(len, idx - start);
        return len;
    }
};